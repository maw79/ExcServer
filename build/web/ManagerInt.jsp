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
        <title>Manager Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <div>Welcome to the Manager System!</div>
        <div>Select your task below.</div>
        <form action="ManagerDirect" method="POST">
            <select name="selection">
                <option>Add Product</option>
                <option>Remove Product</option>   
                <option>Update Product</option>
                <option>Print Transaction Log</option>
                <option>Log Out</option>
            </select>
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
