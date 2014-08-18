/*------------------------------------------------------------------------
 # MegaSlide - Sep 17, 2013
# ------------------------------------------------------------------------
# Websites:  http://www.megadrupal.com -  Email: info@megadrupal.com
--------------------------------------------------------------------------*/

(function(e){e.fn.triggerItemEvent=function(){var t=e(this).data("slidepanel");if(t==null)return;var n=e(this);n.draggable({containment:"parent",drag:function(r,i){var s=Math.round(e(i.helper).position().left),o=Math.round(e(i.helper).position().top);n.data("left",s);n.data("top",o);t.toolbar.changePositionValue(s,o)}});n.resizable({handles:"e, s, se",containment:"parent",resize:function(r,i){var s=Math.round(e(i.helper).width()),o=Math.round(e(i.helper).height());n.data("width",s);n.data("height",o);t.toolbar.changeSizeValue(s,o)}});n.bind("mousedown",function(n){if(n.shiftKey){if(!e(this).hasClass("ui-selected")){e(this).addClass("ui-selected");t.triggerChangeSelectItem()}}else{if(!e(this).hasClass("ui-selected")){e(this).siblings(".slider-item").removeClass("ui-selected");e(this).addClass("ui-selected");t.triggerChangeSelectItem()}else{if(e(this).siblings(".slider-item.ui-selected").size()>0){e(this).siblings(".slider-item.ui-selected").removeClass("ui-selected");t.triggerChangeSelectItem()}}}});return this};e.fn.getItemValues=function(){if(e(this).hasClass("slider-item")){var t=e(this).data(),n={width:100,height:50,left:0,top:0,starttime:0,stoptime:0,startani:"",stopani:"",startaniTime:0,stopaniTime:0,opacity:100,style:"",zindex:"",type:"",title:"",color:"",backgroundColor:"",backgroundTransparent:"",border:0,borderAll:"none",borderTop:"none",borderRight:"none",borderBottom:"none",borderLeft:"none",borderTopLeftRadius:"",borderTopRightRadius:"",borderBottomRightRadius:"",borderBottomLeftRadius:"",padding:0,paddingTop:"",paddingRight:"",paddingBottom:"",paddingLeft:"",shadow:0,shadowAngle:0,shadowOffset:0,shadowBlur:0,shadowColor:"#000",fontSize:"",fontFamily:"",fontWeight:"",lineHeight:"",textDecoration:"",textTransform:"",textAlign:"",link:"",linkColor:"",linkBorderColor:"",linkBackgroundColor:"",linkTarget:"",linkCustomClass:"",customClass:"",customCss:"",fileid:"",thumb:"",thumbid:""},r={};for(var i in n){r[i]=t[i]}return e.extend(n,r)}return null};e.fn.setItemValues=function(t){if(e(this).hasClass("slider-item")){e(this).data(t);return true}return null};e.fn.setItemStyle=function(t){if(e(this).hasClass("slider-item")){var n={};if(t.customClass)e(this).addClass(t.customClass);if(t.width)n["width"]=t.width;if(t.height)n["height"]=t.height;if(t.top)n["top"]=t.top;if(t.left)n["left"]=t.left;if(t.opacity)n["opacity"]=t.opacity;if(t.backgroundColor){n["background-color"]=t.backgroundColor}if(t.borderTop)n["borderTop"]=t.borderTop;if(t.borderRight)n["borderRight"]=t.borderRight;if(t.borderBottom)n["borderBottom"]=t.borderBottom;if(t.borderLeft)n["borderLeft"]=t.borderLeft;if(t.borderTopLeftRadius)n["border-top-left-radius"]=t.borderTopLeftRadius+"px";if(t.borderTopRightRadius)n["border-top-right-radius"]=t.borderTopRightRadius+"px";if(t.borderBottomRightRadius)n["border-bottom-right-radius"]=t.borderBottomRightRadius+"px";if(t.borderBottomLeftRadius)n["border-bottom-left-radius"]=t.borderBottomLeftRadius+"px";if(t.paddingTop)n["padding-top"]=t.paddingTop+"px";if(t.paddingRight)n["padding-right"]=t.paddingRight+"px";if(t.paddingBottom)n["padding-bottom"]=t.paddingBottom+"px";if(t.paddingLeft)n["padding-left"]=t.paddingLeft+"px";if(t.shadow){var r=t.shadowAngle,i=t.shadowOffset,s=t.shadowBlur,o=t.shadowColor;if(r!=null&&i!=null&&s!=null&&o!=null){var u=Math.round(i*Math.cos((r-90)/180*Math.PI)),a=Math.round(i*Math.sin((r-90)/180*Math.PI)),f=u+"px "+a+"px "+parseInt(s)+"px "+o;n["box-shadow"]=f}else{n["box-shadow"]="none"}}if(t.zindex){n["z-index"]=t.zindex}if(t.type=="text"){if(t.fontSize)n["font-size"]=t.fontSize+"px";if(t.lineHeight)n["line-height"]=t.lineHeight+"px";if(t.fontFamily)n["font-family"]='"'+t.fontFamily+'"';if(t.fontWeight){var l=t.fontWeight.toString();if(l.indexOf("italic")>0){n["font-weight"]=parseInt(l);n["font-style"]="italic"}else{n["font-weight"]=parseInt(l);n["font-style"]="normal"}}if(t.textDecoration)n["text-decoration"]=t.textDecoration;if(t.textTransform)n["text-transform"]=t.textTransform;if(t.textAlign)n["text-align"]=t.textAlign;if(t.color)n["color"]=t.color}e(this).css(n)}return false};e.fn.setItemHtml=function(t){if(e(this).hasClass("slider-item")){if(t.type=="text"){e(this).find("div").html(t.title.replace(/\n/g,"<br />"))}else{e(this).find("img").attr("src",t.thumb)}}return false};e.HexToRGB=function(e){var e=parseInt(e.toString().indexOf("#")>-1?e.substring(1):e,16);return{r:e>>16,g:(e&65280)>>8,b:e&255}};e.removeMinusSign=function(e){return e.replace(/-/g,"")};e.objectToString=function(e){return JSON.stringify(e)};e.stringToObject=function(e){try{return jQuery.parseJSON(e)}catch(t){return{}}};window.MdImagePopup=function(t){function r(e){t.onSubmit.call(this,e[0].url,{fileid:e[0].fid,name:e[0].filename})}var n={onSubmit:function(e,t){}};t=e.extend({},n,t);this.open=function(){Drupal.media.popups.mediaBrowser(r)};this.open()};window.submitVideo=function(t,n){var r=t.match(/(?:https?:\/{2})?(?:w{3}\.)?youtu(?:be)?\.(?:com|be)(?:\/watch\?v=|\/)([^\s&]+)/);if(r!=null){e.getJSON("http://gdata.youtube.com/feeds/api/videos/"+r[1]+"?v=2&alt=jsonc",function(e){if(e.data){var t=e.data;n.call(null,{id:t.id,title:t.title,thumb:t.thumbnail.hqDefault})}})}else{var i=/vimeo.*\/(\d+)/i.exec(t);if(i!=null){e.getJSON("http://vimeo.com/api/v2/video/"+i[1]+".json?callback=?",{format:"json"},function(e){if(e){n.call(null,{id:e[0].id,title:e[0].title,thumb:e[0].thumbnail_medium})}})}}}})(jQuery)