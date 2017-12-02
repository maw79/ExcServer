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
        <%--retrieve total variable--%>
        <table border ="0">
            <tr>Welcome to the Cash Payment System!</tr>
            
            <tr>
                <td>Total Due: </td>
                <td>!!!!</td>
            </tr>
            <form action="CashPayment" method="POST">
            <tr>
                <td>Enter Payment Amount:</td>
                <td><input name="cash" id="cash" type="number" step=".01"></input>
            </tr>
        </table>
            <input type="submit" value="Insert Cash">
            </form>
    </body>
</html>
