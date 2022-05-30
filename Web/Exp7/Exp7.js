
function formValidation(){

var email = document.getElementById('email');
var password =  document.getElementById('password');
var number =  document.getElementById('number');

emailVal(email, "* Please enter a valid email address like abc@xyz *")
passVal(password, "* Please enter a valid password,  please use atleast one number, one UpperCase and one LowerCase Alphabet *");
numberVal(number, "* Please enter a valid 10-digit phone number *")
}

function emailVal(inputtext, alertMsg){

var emailExp = /^[\w\-\.\+]+\@[a-zA-Z0-9\.\-]+\.[a-zA-z0-9]{2,4}$/;
if(inputtext.value.match(emailExp))
    alertMsg = "*Email Is Valid *"; 
document.getElementById('p1').innerText = alertMsg; 
}

function passVal(inputtext, alertMsg){

var LetterDigitExp = "^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])[a-zA-Z0-9]+$";
if(inputtext.value.match(LetterDigitExp))
    alertMsg = "*Password Is Valid *"; 
document.getElementById('p2').innerText = alertMsg; 
}

function numberVal(inputtext, alertMsg){

var numericExpression = /^[0-9]+$/;
if(inputtext.value.match(numericExpression)&&inputtext.value.length==10)
alertMsg = "*Phone Number Is Valid *";
document.getElementById('p3').innerText = alertMsg;  
}
