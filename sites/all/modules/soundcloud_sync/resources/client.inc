<?php

/**
 * SoundCloud API wrapper for Drupal CMS.
 *
 * @category  Drupal Modules
 * @package   SoundCloud Sync
 * @author    Vlad Savitsky <vlad.savitsky@gmail.com>
 * @copyright 2015 Vlad Savitsky <vlad.savitsky@gmail.com>
 * @license   http://www.opensource.org/licenses/mit-license.php MIT
 * @link      https://github.com/VladSavitsky
 */
class SoundCloudClient {

  /**
   * SoundCloud API Client object.
   *
   * @access public
   */
  public $service;

  /**
   * Place to store private properties and use getters and setters.
   *
   * @var array
   * @access private
   */
  private $settings = array();

  /**
   * Url to redirect from SoundCloud authorization page.
   *
   * @var string
   * @access public
   */
  public $redirectUrl = '';

  /**
   * Client class constructor.
   *
   * @access protected
   * @return void
   */
  function __construct() {
    $this->accessToken = variable_get('soundcloud_sync_accessToken', '');
    $this->clientId = variable_get('soundcloud_sync_clientId', '');
    $this->clientSecret = variable_get('soundcloud_sync_clientSecret', '');

    try {
      $this->service = new Services_Soundcloud(
        $this->clientId,
        $this->clientSecret,
         // TODO: Implement ability to change this url.
         //       Be sure to update connection help text at form.
        url('admin/config/services/soundcloud/client', array('absolute' => true))
      );
    }
    catch (Services_Soundcloud_Missing_Client_Id_Exception $e) {
      watchdog('soundcloud', $e->getHttpCode() . '. ' .$e->getMessage(), array(), WATCHDOG_ERROR);
    }

    // This token will allow to use service resources after success connection.
    if (!empty($this->accessToken)) {
      $this->service->setAccessToken($this->accessToken);
    }
  }

  // Reload properties

  public function __set($name, $value) {
    $this->settings[$name] = $value;
    if (variable_get('soundcloud_sync_' . $name) != $value) {
      variable_set('soundcloud_sync_' . $name, $value);
    }
  }

  public function __get($name) {
    return isset($this->settings[$name]) ? $this->settings[$name] : FALSE;
  }

  public function __isset($name) {
    return isset($this->settings[$name]);
  }

  // Connection

  public function isConnected() {
    return (boolean) !empty($this->accessToken) && strlen($this->accessToken) ==32 && strpos($this->accessToken, '-');
  }

  /**
   * Obtain an access_token from SoundCloud.com using temporary code.
   *
   * @param string $code
   *  Temporary code recieved from SoundCloud to authorize the app.
   *
   * @access public
   * @return void
   */
  public function connect($code) {
    // Get 'access_token' from SoundCloud.com.
    $response = $this->service->accessToken($code);
    // Store token for later use.
    $this->accessToken = $response['access_token'];
  }

  /**
   * Get authorization URL.
   *
   * @access public
   * @return void
   */
  public function getConnectUrl() {
    // Request non-expiring token which shouldn't be refreshed.
    // @see https://developers.soundcloud.com/blog/non-expiring-tokens
    $params = array('scope' => 'non-expiring');
    return $this->service->getAuthorizeUrl($params);
  }
}
