<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title>Customer Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <div>Welcome to the Debit Card Payment System!</div>
        <form action="PayCard" method="POST">
            <table border ="0">
            <tr>
                <td><br>Name on Card: <input type="string" name="name"></input></td>                
                <td><br>Card Number: <input type="string" name="cardNo"></input></td>
                <td><br>Pin Number: <input type="string" name="pin"></input></td>
            </tr>
            </table>
        </form> 
    </body>
</html>