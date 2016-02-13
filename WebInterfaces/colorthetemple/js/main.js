$(window).on("load", setup);
	      
// Spacebrew Object
var sb, app_name = "CTT Remote";

var disconnectColor = "#F0A0A0";

/**
 * setup Configure spacebrew connection and adds the mousedown listener.
 */
function setup (){

	$('body').css('background-color', disconnectColor);

	// create spacebrew client object
	sb = new Spacebrew.Client(window.location.hostname, { reconnect: true });

	// set the base description
	sb.name(app_name);
	sb.description("Web remote for Color the Temple by the Met MediaLab");

	// configure the publication and subscription feeds
	sb.addPublish("trigger", "string", "");
	sb.addPublish("autoplay", "boolean", "");
	sb.addPublish("autoplay-duration", "range", "");

	// override Spacebrew events - this is how you catch events coming from Spacebrew
	sb.onOpen = onOpen;
	sb.onClose = onClose;

	// connect to spacbrew
	sb.connect();

	// listen to the mouse 
	$("button").on("mousedown", onButtonPress);
}	

/**
 * Function that is called when Spacebrew connection is established
 */
function onOpen() {
	$('body').css('background-color', 'white');
}

/**
 * Function that is called when Spacebrew connection is closed
 */
function onClose() {
	$('body').css('background-color', disconnectColor);
}

/**
 * Function that is called whenever the button is pressed.  
 * @param  {Event object} evt Holds information about the button press event
 */
function onButtonPress (evt){
    // console.log("[onButtonPress] " + $(this).attr("id")); 
    var id = $(this).attr("id");

    if (id == "autoplay") {
    	if ($(this).hasClass("btn-success")) {
    		$(this).addClass("btn-danger");
    		$(this).removeClass("btn-success");
    		$(this).text("Autoplay Off");
    		sb.send("autoplay", "boolean", "false");
    	} else {
			$(this).removeClass("btn-danger");
    		$(this).addClass("btn-success");
    		$(this).text("Autoplay On");
    		sb.send("autoplay", "boolean", "true");
    	}
    	
    }
    else if (id == "autoplay-duration-set") {
    	sb.send("autoplay-duration", "range", $("#autoplay-duration").val());
    	$("#autoplay-duration-set").text("Set duration ✔");
    	setTimeout(function() {
    		$("#autoplay-duration-set").text("Set duration");
    	}, 5 * 1000)
    }
    else {
    	sb.send("trigger", "string", $(this).attr("id"));
    }
}
