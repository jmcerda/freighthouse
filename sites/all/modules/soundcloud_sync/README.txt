
----------------------------------
SoundCloud_Sync 1.x for Drupal 7.x
----------------------------------

While other SoundCloud-related modules downloads sounds from SoundCloud.com
this module upload them and sync. This module do not provide the player.

This module uploads and sync sound-files attached to nodes to SoundCloud.com.

When users add/update/remove node which has a file-field configured to
sync sound-files with SoundCloud those files will be automatically updated
at SoundCloud.com.

Users can attach any number of files to one filed. You could have unlimited
number of fields which will sync with SoundCloud.com. But for now you're limited
to one account at SoundCloud.com per site.

------------
Installation
------------

SoundCloud_Sync can be installed like any other Drupal module -- place it in
the modules directory for your site and enable it on the `admin/build/modules` page.

For now module was installed.

Then you need to connect your site to account at SoundCloud.com.
Note: SoundCloud calls your site an 'app'.

1. Login to your account at SoundCloud.com or create new account.
2. Open Admin/Configuration/Web Services/SoundCloud Sync Setting
   (admin/config/services/soundcloud )
3. Open http://soundcloud.com/you/apps in new window (Ctrl + click).
4. Click 'Register new app' button or select existing one.
5. Use your site name as app title.
6. Enter 'Redirect URL'. Should be:
   http://example.com/admin/config/services/soundcloud/client
7. Click 'Save'.
8. Copy and paste 'Client ID' and 'Client Secret' into fields below.
9. Click 'Connect' button.
10. Follow the instractions provided by SoundCloud.com.

If your site was sucessfully connected to SoundCloud.com you will see a green
status message at the top. In other case you will see an error message.
Fix errors and reconnect again.

For now your site was connected to your account at SoundCloud.com.

Then you need to configure field which should sync with SoundCloud.com

1. Open existing content type settings or create new content type.
2. Add FILE field to content type or edit existing FILE field.
2. Make this field syncable (enable syncing with SoundCloud) and configure
   this field. When node will be inserted/updated/deleted the same actions
   will be done with related tracks at SoundCloud.com.
3. Save settings.

Now it's time to test configuration. Internet connection required. In offline
mode nodes won't be synced with SoundCloud and you need to re-save nodes later.

1. Create a node and attach file.
2. Save node.
3. Open SoundCloud account page.
Expected results: File attached to node should be uploaded to SoundCloud.

Note: SoundCloud has a queue for uploaded files and your file could be shown
with some delay.

-----------
Maintainers
-----------

- VladSavitsky (Vlad Savitsky)
