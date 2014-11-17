<!-- Intro loader -->
<div class="mask">
    <div id="intro-loader"></div>
</div>
<!-- Intro loader -->
<?php if($page['header']):?>
    <?php print render($page['header']);?>
<?php endif;?>

<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>
<?php print $messages;?>

<?php if($page['about']):?>
<!-- About Section -->
    <section id="about" class="section-content">
        <?php print render($page['about']);?>
    </section>
<!-- About Section -->
<?php endif;?>

<?php if($page['parallax_one']):?>
    <!-- Parallax Container -->
        <!-- john commented and update into section to make the menu work and highlighted acoordingly-->
        <!--<div id="one-parallax" class="parallax"  data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">-->
        <section id="one-parallax consulting" class="parallax section-content" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
            <?php print render($page['parallax_one']);?>
        </section>    
        <!--</div>-->
        <!-- end john comment-->
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['service']):?>
    <!-- Service Section -->
    <section id="service" class="section-content">
        <?php print render($page['service']);?>
    </section>
    <!-- Service Section -->
<?php endif;?>

<?php if($page['parallax_two']):?>
    <div id="two-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_two']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['parallax_three']):?>
    <!-- Parallax Container -->
    <div id="three-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_three']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['team']):?>
    <!-- Team Section -->
    <section id="team" class="section-content">
        <?php print render($page['team']);?>
    </section>
    <!-- Team Section -->
<?php endif;?>

<?php if($page['parallax_four']):?>
    <!-- Parallax Container -->
    <div id="four-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_four']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['location']):?>
    <!-- Location Section -->
    <section id="location" class="section-content">
        <?php print render($page['location']);?>
    </section>
    <!-- location Section -->
<?php endif;?>

<?php if($page['client']):?>
    <!-- Client Section -->
    <section id="client" class="section-content">
        <?php print render($page['client']);?>
    </section>
    <!-- Client Section -->
<?php endif;?>

<?php if($page['parallax_five']):?>
    <!-- Parallax Container -->
    <div id="five-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_five']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['portfolio']):?>
    <!-- Portfolio Section -->
    <section id="portfolio" class="section-content">
        <?php print render($page['portfolio']);?>
    </section>
    <!-- Portfolio Section -->
<?php endif;?>

<?php if($page['pricing']):?>
    <!-- Pricing Section -->
    <section id="pricing" class="section-content">
        <?php print render($page['pricing']);?>
    </section>
    <!-- Pricing Section -->
<?php endif;?>

<?php if($page['parallax_six']):?>
    <!-- Parallax Container -->
    <div id="six-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_six']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['blog']):?>
    <!-- Blog Section -->
    <section id="blog" class="section-content timeline-content bgdark">
        <?php print render($page['blog']);?>
    </section>
    <!-- Blog Section -->
<?php endif;?>

<?php if($page['parallax_seven']):?>
    <!-- Parallax Container -->
    <div id="seven-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_seven']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['contact']):?>
    <!-- Contact Section -->
    <section id="contact" class="section-content">
        <?php print render($page['contact']);?>
    </section>
    <!-- Contact Section -->
<?php endif;?>
    <section id="assoc" class="section-content">
        <img src="<?php echo drupal_get_path('theme', 'freighthouse')?>/images/Drupal_Association_org_mem.png" alt="drupal association"/>
        <img src="<?php echo drupal_get_path('theme', 'freighthouse')?>/images/freelancersunion_member.png" alt="freelancer union"/>        
    </section>

<?php if($page['footer']):?>
    <?php print render($page['footer']);?>
<?php endif;?>
 <a href="#" id="back-top"><i class="fontello icon-angle-up icon-2x"></i></a>
