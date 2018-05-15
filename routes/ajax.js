var rpio = require('rpio');



/* GET ajax response. */
module.exports = function(req, res) {
    
    if (req.body.hasOwnProperty('action')) {
        rpio.init({mapping: 'gpio'});
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

            case 'carriage C':
            //    rpio.init({mapping: 'gpio'});
            //    rpio.open(req.body.gpio, rpio.OUTPUT, + req.body.status);
            //    rpio.write(req.body.gpio, + req.body.status);
            //    res.contentType('json');
            //    res.send({ gpio: req.body.gpio, status: req.body.status });

                console.log("focus C");
                console.log((req.body.status) ? "forward" : "back");

                // set direction
                dirPin = 17;
                
                rpio.open(req.body.gpio, rpio.OUTPUT, + req.body.status);
                rpio.write(dirPin, req.body.status);
            //    res.contentType('json');

                console.log("76");
                console.log(req.body.gpio);
            //    res.send({ gpio: req.body.gpio, status: req.body.status });

                // test: do a full revolution of the carriage motion thing
                gpioPin = 26; // for GPIO 26
                for(var i = 0; i < /*(2*200*16) - 1*/ 100; i++){ // (stepsPerRev * microstepping * 2) - 1. (as it's a half cycle) - is there a fencepost error here?
                    // cycle state
                    sleaep(10); 
                    rpio.write(gpioPin, !rpio.read(gpioPin));
                    res.contentType('json');
                    res.send({ gpio: gpioPin, status: rpio.read(gpioPin) }); 
                }


                break;
        }
    }                                           
    // res.contentType('json');                 
    // res.send({ some: req.body.action });     

};


function sleaep(milliseconds) {
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++) {
    if ((new Date().getTime() - start) > milliseconds){
      break;
    }
  }
}
