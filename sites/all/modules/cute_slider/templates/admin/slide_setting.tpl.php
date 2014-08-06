<?php
/**
 * @file slide_setting.tpl.php
 * User: duynguyen
 * Date: 4/3/13
 * Time: 12:13 PM
 * To change this template use File | Settings | File Templates.
 */
?>
<div id='slide-setting-dlg' title="Slide setting">
    <div class="cuteslider-popup clearfix">
        <div id="slide-setting-tabs" class="cs-popup-tabs clearfix">
            <ul class="navbar unstyled clearfix">
                <li class="active"><a href="#tab-1">Image & Trasitions</a></li>
                <li><a href="#tab-2">Link Slide</a></li>
                <li><a href="#tab-3">Info box</a></li>
                <li><a href="#tab-4">Slide video</a></li>
            </ul>
            <!-- div#tab-1 - Images & Transition -->
            <div id="tab-1" class="tab-image">
                <div class="slide-setting clearfix">
                    <h3>Slide settings</h3>
                    <div class="choose-image">
                      <a class="slide-choose-image-link" href="#">[Choose image]</a>
                      <div id="slide-background-preview"></div>
                    </div>
                    <input type="hidden" id="slide-backgroundimage">
                    <div class="choose-thumbnail">
                      <a class="slide-choose-thumbnail-link" href="#">[Choose thumbnail]</a>
                      <div id="slide-thumbnail-preview"></div>
                    </div>
                    <input type="hidden" id="slide-thumbnail">
                </div><!-- / .slide-setting -->
                <div class="transition">
                    <h3>Transitions <a href="#" class="random-transition">Choose random</a></h3>
                    <p>You can select multiple value, slide will take random effect form what you selected. You have to choose 3D and 2D effects, 2D effects will be using in old browsers that do not support 3D transitions.</p>
                    <div id="navbar-content-transitions" class="transition-inner">
                        <ul class="navbar-transition unstyled clearfix">
                            <li class="active"><a href="#navbar-content-3D">3D Transitions</a></li>
                            <li><a href="#navbar-content-2D">2D Transitions</a></li>
                        </ul>
                        <div id="navbar-content-3D" class="navbar-content-3D navbar-content-tr clearfix">
                            <?php for($i = 0; $i < 4; $i++): ?>
                              <ul class="columns unstyled">
                                <?php for($j = 1; $j <= 16; $j++): ?>
                                    <li data-id="<?php print 16 * $i + $j;?>"><label><input type="checkbox" value="<?php echo 16 * $i + $j ?>"/><span>Transitions #<?php echo 16 * $i + $j ?></span></label></li>
                                <?php endfor;?>
                              </ul>
                            <?php endfor;?>
                        </div>
                        <div id="navbar-content-2D" class="navbar-content-2D navbar-content-tr clearfix">
                            <?php for($i = 0; $i < 4; $i++): ?>
                              <ul class="columns unstyled">
                                <?php $rows = $i == 3 ? 8 : 11 ?>
                                <?php for($j = 1; $j <= $rows; $j++): ?>
                                  <li data-id="<?php echo 11 * $i + $j ?>"><label><input type="checkbox" value="<?php echo 11 * $i + $j ?>"/><span>Transitions #<?php echo 11 * $i + $j ?></span></label></li>
                                <?php endfor;?>
                              </ul>
                            <?php endfor;?>
                        </div>
                    </div>
                </div><!-- / .transitions -->
            </div><!-- / .tab-1 Images & Transition-->
            <div id="tab-2">
                <label for="slide-link">Link slide</label>
                <input type="text" id="slide-link" class="insert-input">
                <label><input type="checkbox" id="slide-link-target"> <span>Open in new windows</span>
            </div>
            <div id="tab-3" class="clearfix">
                <div class="column-info-box">
                    <label for="slide-info-position">Position</label>
                    <select id="slide-info-position" name="slide-info-position">
                        <option value="top">top</option>
                        <option value="right">right</option>
                        <option value="bottom">bottom</option>
                        <option value="left">left</option>
                    </select>
                </div>
                <div class="column-info-box">
                    <label for="slide-info-title">Title</label>
                    <input type="text" id="slide-info-title" class="insert-input">
                    <label for="slide-info-text">Text</label>
                    <textarea id="slide-info-text"></textarea>
                </div>
                <div class="column-info-box">
                    <label for="slide-info-button-text">Link button text</label>
                    <input type="text" class="insert-input" id="slide-info-button-text" placeholder="read more">
                    <label for="slide-info-button-link">URL</label>
                    <input type="text" id="slide-info-button-link" class="insert-input">
                    <label><input type="checkbox" id="info-link-target"> <span>Open in new windows</span>
                </div>
            </div>
            <div id="tab-4">
                <label for="slide-video-url">Video URL</label>
                <input type="text" id="slide-video-url" class="insert-input">
                <p>Support Youtube/Vimeo video. You must choose slide image first</p>
            </div>
        </div><!-- / .cs-popup-tabs -->
    </div>
</div>