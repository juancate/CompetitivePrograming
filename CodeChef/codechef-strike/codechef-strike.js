var DEBUG = true;
var DEBUG_TRACE = false;

  // create div for logging
if (DEBUG) $("body").append( "<div id='betlista-codechef-strike-log'></div>");
  // get this log div
var logDiv;
if (DEBUG) logDiv = $('#betlista-codechef-strike-log');

function processProfilePage(data) {
	var url = window.location.href;
	if (DEBUG) logDiv.append("DEBUG: url='" + url + "'<br>");
	if ( url === 'http://www.codechef.com/' || /http:\/\/www.codechef.com\/users\//.test( url ) ) {
		// do not modify recent activity table on main page
		// do not modify recent activity table on users page
		if (DEBUG) logDiv.append("DEBUG: ending processProfilePage, url matched<br>");
		return;
	}
	if (DEBUG) logDiv.append("DEBUG: processing profile page<br>");
	  //alert('Load was performed:' + data);
	var profileHtml = jQuery( data );
	var profileDiv = $( 'div.profile', profileHtml );
	//var profileDiv = $( 'div.profile');
	
	  // get problem codes solved in contest
	  // get <a> tags with problem codes
	var problemTds = $('table:eq(1) > tbody > tr:last > td:eq(1)', profileDiv);
	var contestSearchString = 'p:contains("' + contest + '") > span > a';
	var aTags = $( "span > a", $( "p", profileDiv).not(':contains("Practice Problems")') );
	var codesList = '';
	aTags.each( function(i) { if ( i == 0 ) codesList = $(this).text(); else codesList = codesList + ',' + $(this).text(); } );
	
	if (DEBUG) logDiv.append( "DEBUG: contest problem codes: " + codesList + "<br>");
	var codes = codesList.split(',');
	var contest = new Array();
	var code;
	for ( var i = 0; i < codes.length; ++i ) {
		code = codes[i];
		if (DEBUG) logDiv.append( "contest[" + code + "]=1<br>" );
		contest[code] = 1;
	}
	
	  // get problem codes solved in practice
	var practiceSearchString = 'p:contains("Practice Problems") > span > a';
	aTags = $( practiceSearchString, problemTds);
	codesList = '';
	aTags.each( function(i) { if ( i == 0 ) codesList = $(this).text(); else codesList = codesList + ',' + $(this).text(); } );
	
	if (DEBUG) logDiv.append( "DEBUG: practice problem codes: " + codesList + "<br>");
	codes = codesList.split(',');
	var practice = new Array();
	for ( var i = 0; i < codes.length; ++i ) {
		code = codes[i];
		if (DEBUG) logDiv.append( "practice[" + code + "]=1<br>" );
		practice[code] = 1;
	}
	
	// get problem rows
	var problemsTable = $( "table.problems:first" );
	$("tbody > tr.headerrow", problemsTable ).prepend('<th class="headerrow"></th>');
	var problemRows = $("tr.problemrow", problemsTable);
	problemRows.prepend('<td></td>');
	var codeTd;
	var code;
	problemRows.each( function(i) {
		codeTd = $("td:eq(2)", $(this));
		code = codeTd.text();
		//alert(code);
		if (DEBUG) logDiv.append( "code='" + code + "'<br>");
		if ( contest[code] == 1 ) {
			  // add green tick and strike
			$("td:first", $(this)).html('<img src="http://i.imgur.com/qM032.gif">');
			$("td:gt(0)", $(this)).addClass('betlista-codechef-strike');
		} else if ( practice[code] == 1 ) {
			  // add orange tick and strike
			$("td:first", $(this)).html('<img src="http://i.imgur.com/K5uMw.gif">');
			$("td:gt(0)", $(this)).addClass('betlista-codechef-strike');
		}
	});
	
	var problemCode = url.replace( /.*problems\/([^\/]*)\/?/, "$1" );
	var problemHeaderTable = $( "table.pagetitle-prob");
	if ( problemHeaderTable != null ) {
		var header = $( "tbody > tr > td:eq(0) > h1", problemHeaderTable);
		if ( practice[problemCode] == 1 ) {
			header.prepend('<img src="http://i.imgur.com/K5uMw.gif">');
		}
		if ( contest[problemCode] == 1 ) {
			header.prepend('<img src="http://i.imgur.com/qM032.gif">');
		}
	}
}

  // log start
if (DEBUG_TRACE) logDiv.append( "TRACE: cc-strike start<br>");

  // check if user is logged in
var userBarDiv = $("#user-bar > div");
var clazz = userBarDiv.attr( "class" );
if ( clazz == "login-user") { // if logged in
	if (DEBUG) logDiv.append( "TRACE: you are logged in<br>" );
	  // get profile page
	var profile = $( 'a:contains("Account")', userBarDiv ).attr("href");
	$.get( profile, function(data) { processProfilePage(data); } );
} else {
	if (DEBUG_TRACE) logDiv.append( "TRACE: you are not logged in" );
}

if (DEBUG) logDiv.append( "TRACE: cc-strike end<br>");
