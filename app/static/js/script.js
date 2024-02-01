document.addEventListener("DOMContentLoaded", function() {
    var socket = io.connect('http://' + document.domain + ':' + location.port);

    var buttons = document.getElementsByClassName('planeta');
    Array.from(buttons).forEach(function(planeta) {
        planeta.addEventListener('click', function() {
            socket.emit(planeta.id);
            console.log(planeta.id);
            window.open(planeta.getAttribute('data-href'), '_self');
        });
    });
});