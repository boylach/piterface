$(function(){				
    $('.gpio-checkbox').on('change', function(e){        
        var data = {}; // goes into req.body in ajax.js
        data.gpio = $(this).data("gpio");
        data.status = this.checked;
        // data.action = "write";   // original
        //data.action = (data.gpio < 20) ? "write" : "stepperFocusLoop";
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
            case 12:    // carriage +
                data.action = "focus C";f
                data.status = 1;
                break;
            case 6:     // carriage -
                data.action = "focus C";
                data.status = 0;
                break;                
        }



        data.action = (data.gpio == 19)|(data.gpio == 16) ? "focusA" : "write";                 // check if focus A motors
        data.action = (data.gpio == 26)|(data.gpio == 20) ? "focusB" : "write";     // check if focus B motors
        data.action = (data.gpio == 12)|(data.gpio == 6) ? "motionC" : "write";      // check if motion C motor

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
