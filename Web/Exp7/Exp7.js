
function formValidation()
{
var email = document.getElementById('email');
var password =  document.getElementById('password');
var number =  document.getElementById('number');

emailValidation(email, "* Please enter a valid email address like abc@xyz *")
inputPassword(password, "* For your password please use atleast one number, one UpperCase and one LowerCase Alphabet *");
numberValidation(number, "* Please enter a valid 10-digit phone number *")
}
function emailValidation(inputtext, alertMsg)
{
var emailExp = /^[\w\-\.\+]+\@[a-zA-Z0-9\.\-]+\.[a-zA-z0-9]{2,4}$/;
if(inputtext.value.match(emailExp))
{
document.getElementById('p1').innerText = "* Entered Email Is Valid *"; 
}
else
{
document.getElementById('p1').innerText = alertMsg; 
}
}
function inputPassword(inputtext, alertMsg){
var LetterDigitExp = "^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])[a-zA-Z0-9]+$";
if(inputtext.value.match(LetterDigitExp))
{
document.getElementById('p2').innerText = "* Entered Password Is Valid *"; 
}
else{
document.getElementById('p2').innerText = alertMsg; 
}
}

function numberValidation(inputtext, alertMsg)
{
var numericExpression = /^[0-9]+$/;
if(inputtext.value.match(numericExpression)&&inputtext.value.length==10)
{
document.getElementById('p3').innerText = "* Entered Phone Number Is Valid *";
}
else
{
document.getElementById('p3').innerText = alertMsg;  
}
}
