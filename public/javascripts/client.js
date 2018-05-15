$(function(){				
    $('.gpio-checkbox').on('change', function(e){        
        var data = {}; // goes into req.body in ajax.js
        data.gpio = $(this).data("gpio");
        data.status = this.checked;
        // data.action = "write";   // original
        data.action = (data.gpio < 20) ? "write" : "stepperFocusLoop";
        console.log(data);
        $.ajax({
            type: 'POST',
            data: JSON.stringify(data),
            contentType: 'application/json',
            url: '/ajax',						
            error: function(data) {
                alert("Error");
            }
        });
    });				
});