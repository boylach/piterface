$(function(){				
    $('.gpio-checkbox').on('change', function(e){        
        var data = {}; // goes into req.body in ajax.js
        data.gpio = $(this).data("gpio");
        data.status = this.checked;
        // data.action = "write";   // original
        switch(data.gpio) {
            case 19:    // focus A +
                data.action = "focus A";
                data.status = 1;
                break;
            case 16:    // focus A -
                data.action = "focus A";
                data.status = 0;
                break;
            case 26:    // focus B +
                data.action = "focus B";
                data.status = 1;
                break;
            case 20:    // focus B -
                data.action = "focus B";
                data.status = 0;
                break;
            case 6:    // carriage +
                data.action = "carriage C";
                data.status = 1;
                break;
            case 12:     // carriage -
                data.action = "carriage C";
                data.status = 0;
                break;
            default:
                data.action = "write";       
        }

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
