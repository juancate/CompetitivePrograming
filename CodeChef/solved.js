/*
	Solved problems marker for CodeChef 
	author: Victor Padilla (vector9x)
	Date: Jan 17 / 2010
*/

var userPage = "http://www.codechef.com/users/juancate";

function readSolved() {
    var doc=document.getElementById('myiframe').contentDocument;

    var iterator = doc.evaluate("//a[contains(@href,'/status')]", doc, null, XPathResult.UNORDERED_NODE_SNAPSHOT_TYPE, null);
    var isSolved=[];
    for(i=0; i<iterator.snapshotLength; i++) {
        var problemcode = iterator.snapshotItem(i).textContent;
        isSolved[problemcode]=true;
    }

    var iteratorTable = document.evaluate("//a[contains(@href,'submit/')]", document, null, XPathResult.UNORDERED_NODE_SNAPSHOT_TYPE, null);
    for(i=0; i<iteratorTable.snapshotLength; i++) {
        var a =iteratorTable.snapshotItem(i);
        if(isSolved[a.textContent]) {
            a.parentNode.style['background']='#EEEDEC';
            a.innerHTML = "<nobr><img src='/misc/tick-icon.gif' />" + a.textContent+'</nobr>';
        }
    }
}

var body = document.getElementsByTagName('body')[0];

var script = document.createElement('script');
script.innerHTML = readSolved.toString();
body.appendChild(script)

var div = document.createElement("div");
div.innerHTML="<iframe id='myiframe' src='"+userPage+"' style='visibility:hidden' onload='readSolved()'/>";
body.appendChild(div);