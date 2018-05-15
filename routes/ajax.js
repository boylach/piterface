var rpio = require('rpio');



/* GET ajax response. */
module.exports = function(req, res) {
    
    if (req.body.hasOwnProperty('action')) {
        switch( req.body.action) {
            case 'write': 
                /*gpio.setup(req.body.gpio, gpio.DIR_OUT, function() {
                    gpio.write(req.body.gpio, req.body.status, function(err) {
                        
                        res.contentType('json');
                        res.send({ gpio: req.body.gpio, status: req.body.status, error: err });
                        if (err) throw err;
                        console.log('Written to pin');
                    });
                });*/
                rpio.init({mapping: 'gpio'});
                rpio.open(req.body.gpio, rpio.OUTPUT, + req.body.status);
                rpio.write(req.body.gpio, + req.body.status);
                res.contentType('json');
                res.send({ gpio: req.body.gpio, status: req.body.status });
                break;

            case 'focus A':
                rpio.init({mapping: 'gpio'});
                rpio.open(req.body.gpio, rpio.OUTPUT, + req.body.status);
                rpio.write(req.body.gpio, + req.body.status);
                res.contentType('json');
                res.send({ gpio: req.body.gpio, status: req.body.status });

                console.log("focus A");
                console.log((req.body.status) ? "forward" : "back");
                // test: do a full revolution of the carriage motion thing
                //for(var i = 0; i < 200*16 - 1; i++){ // stepsPerRev * microstepping
                    // cycle state
                //    slee

                //    sleep()
                //}
                break;

            case 'focus B':
                rpio.init({mapping: 'gpio'});
                rpio.open(req.body.gpio, rpio.OUTPUT, + req.body.status);
                rpio.write(req.body.gpio, + req.body.status);
                res.contentType('json');
                res.send({ gpio: req.body.gpio, status: req.body.status });

                console.log("focus B");
                console.log((req.body.status) ? "forward" : "back");
                // test: do a full revolution of the carriage motion thing
                //for(var i = 0; i < 200*16 - 1; i++){ // stepsPerRev * microstepping
                    // cycle state
                //    slee

                //    sleep()
                //}
                break;

            case 'focus C':
                rpio.init({mapping: 'gpio'});
                rpio.open(req.body.gpio, rpio.OUTPUT, + req.body.status);
                rpio.write(req.body.gpio, + req.body.status);
                res.contentType('json');
                res.send({ gpio: req.body.gpio, status: req.body.status });

                console.log("focus C");
                console.log((req.body.status) ? "forward" : "back");
                // test: do a full revolution of the carriage motion thing
                //for(var i = 0; i < 200*16 - 1; i++){ // stepsPerRev * microstepping
                    // cycle state
                //    slee

                //    sleep()
                //}
                break;
        }
      
    }                                           
    // res.contentType('json');                 
    // res.send({ some: req.body.action });     

};
