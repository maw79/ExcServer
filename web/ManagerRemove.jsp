<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<%@page import = "java.util.*"%>
<%--@page import = "main.java"--%>
<html>
    <head>
        <title>Customer Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <div>Welcome to the Interactive Purchase Order System!</div>
        <div>Please proceed with your purchase below.</div>
        <form action="ProdRemove" method="POST">
            <table border ="1">
            <tr>
                <td>Item No</td>
            </tr>
            <tr>
                <td><input type="integer" input="itemNum" name="itemNum"></input></td>
            </tr>
            </table>
        
            <input type="submit" value="Submit and Return">
        </form>
        <form action="ManagerMenu" method="POST">
            <input type="submit" value="Cancel and Return">
        </form>
    </body>
</html>
