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
	sb = new Spacebrew.Client("MDIG9317.local", { reconnect: true });
	// sb = new Spacebrew.Client("localhost", { reconnect: true });

	// set the base description
	sb.name(app_name);
	sb.description("Web remote for Color the Temple by the Met MediaLab");

	// configure the publication and subscription feeds
	sb.addPublish("trigger", "string", "");

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
    sb.send("trigger", "string", $(this).attr("id"));
}