const char webPage[] = 
R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="refresh" content="3">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">     
        <style>           
            *{
                margin: 0;
                padding: 0;
                box-sizing: border-box;
                font-family: 'Poppins',sans-serif;
            }
            ::selection{
                color: #000;
                background: #fff;
            }
            nav{
                position: fixed;
                background: orange;
                width: 100%;
                padding: 15px 0;
                z-index: 12;
            }
            nav .menu{
                max-width: 1250px;
                margin: auto;
                display: flex;
                align-items: center;
                justify-content: space-between;
                padding: 0 20px;
            }
            .menu .logo a{
                text-decoration: none;
                color: #fff;
                font-size: 35px;
                font-weight: 600;
            }
            .menu ul{
                display: inline-flex;
            }
            .menu ul li{
                list-style: none;
                margin-left: 7px;
            }
            .menu ul li:first-child{
                margin-left: 0px;
            }
            .menu ul li a{
                text-decoration: none;
                color: #fff;
                font-size: 18px;
                font-weight: 500;
                padding: 8px 15px;
                border-radius: 5px;
                transition: all 0.3s ease;
            }
            .menu ul li a:hover{
                background: #fff;
                color: black;
            }         
            .temperature-shape {
                position: relative;
                width: 100px;
                top: 30px;
                left: 100px;
                height: 200px;
                background-color: white;
                border-radius: 10px;
                overflow: hidden;
            }
            .temperature-bar {
                position: absolute;
                top: 20px;
                left: 10px;
                width: 80px;
                height: 160px;
                background: linear-gradient(to bottom, #f00 0%, #ff0 50%, #0f0 100%);
            }
            .temperature-mercury {
                position: absolute;
                bottom: 0;
                left: 0;
                width: 100%;
                height: 0;
                background-color: burlywood;
                animation: mercury 2s ease-in-out forwards;
            }
            .temperature-value {
                position: absolute;
                bottom: 15px;
                left: 50%;
                transform: translateX(-50%);
                width: 100%;
                height: 40px;
                line-height: 40px;
                text-align: center;
                font-size: 23px;
                font-weight: 500;
                color: #f00;
            }
            .value {
                display: inline-block;
                text-align: center;
                padding-right: 5px;
                color: #000;
            }     
            .main2{
                margin-top: 50px;
                height: 100px;
            }
            .main{
                align-items: center;
                justify-content: space-between;
                margin-top: 30px;
                margin-left: 50px;
            }
            .unit {
                display: inline-block;
                color: black;
            }

            @keyframes mercury {
                0% { height: 0; }
                100% { height: 20%; }
            }   
            .sun {       
                margin-top: -205px;
                margin-left: 500px;
                width: 100px;
                height: 100px;
                border-radius: 50%;
                background-color: #FDB813;
                box-shadow: 0 0 10px #FDB813,
                    0 0 20px #FDB813,
                    0 0 30px #FDB813,
                    0 0 40px #FDB813,
                    0 0 50px #FDB813,
                    0 0 60px #FDB813,
                    0 0 70px #FDB813,
                    0 0 80px #FDB813,
                    0 0 90px #FDB813;
            }
            .sun-value{
                font-size: 23px;
                text-align: center;
                padding: 10px;
            }
            .land-shape {
                width: 100px;
                height: 100px;
                margin-left: 900px;
                margin-top: -220px;
                background-color: green;
                border-radius: 50%;
                position: relative;
            }
            .land-shape:before {
                content: "";
                display: block;
                position: absolute;
                top: 20%;
                left: 20%;
                width: 60%;
                height: 60%;
                border-radius: 50%;
                background-color: lightgreen;
                box-shadow: inset 0 0 5px rgba(0,0,0,0.5);
            } 
            .land-value{
                font-size: 24px;
                font-weight: bold;
                text-align: center;
                color: white;
            }
            .warning-notice {
                background-color: #ffeeba;
                border: 1px solid #ffc107;
                border-color: red;
                margin-top: 50px;
                padding: 10px;
                font-weight: bold;
                border-radius: 5px;
                position: relative;
                width: 1100px;
                margin-bottom: 20px;
            }
            .warning-notice:before {
                content: '';
                display: block;
                position: absolute;
                top: -10px;
                left: 20%;
                transform: translateX(-50%) rotate(45deg);
                border: 10px solid transparent;

            }
            .warning-notice:after {
                content: '';
                display: block;
                position: absolute;
                bottom: -10px;
                left: 50%;
                transform: translateX(-50%) rotate(45deg);
                border: 10px solid transparent;                
            }
        </style>
    </head>
    <body>
        <nav>
            <div class="menu">
                <div class="logo">
                    <a href="#">Sam Monitoring System</a>
                </div>
                <ul>                   
                    <li><a href="#">Services</a></li>
                    <li><a href="#">Contact</a></li>
                    <li><a href="#">Feedback</a></li>
                </ul>
            </div>
        </nav>
        <div class="main2">
        </div>
        <div class="main">
            <div class="temperature-shape">
                <div class="temperature-bar">
                    <div class="temperature-mercury"></div>
                </div>
                <div class="temperature-value">
                    <span class="value">data1</span>
                    <span class="unit">&deg;C</span>               
                </div>            
            </div>
            <p style="font-size: 17px; margin-top: 60px; margin-left:50px; font-weight: bold;">Environment temperature</p>
            <div class="sun">
                <div class="sun-value">
                    <span class="value">data2</span>
                    <span class="unit">Lux</span>               
                </div>   
            </div>
            <p style="font-size: 17px; margin-top: 85px; margin-left:480px; font-weight: bold;">Intensity of light</p>
            <div class="land-shape"></div>
            <p style="font-size: 24px; margin-top: 20px; margin-left:930px; font-weight: bold;">data3</p>
            <p style="font-size: 17px; margin-top: 30px; margin-left:880px; font-weight: bold;">Humidity of land</p>
            <div class="warning-notice">
                <p>data4</p>
                <p>data5</p>
                <p>data6</p>
            </div>
        </div>
    </body>
</html>
)=====";
