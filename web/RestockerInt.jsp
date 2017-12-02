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
        <title>Restocker Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <div>Welcome to the Restocker System!</div>
        <div>Enter new total stocks below.</div>
        <form action="RestockInventory" method="POST">
        <table border ="1">
            <tr>
                <td>Item No</td>
                <td>Item Name</td>
                <td>In Stock</td>
                <td>New Stock Qty</td>
            </tr>
            <%
                class merchandise{
                public Vector merchandise = new Vector();
                }
                
                //merchandise.size()
                for(int ii=0; ii<5; ii++){%>
                <tr>
                    <td>1</td>
                    <td>2</td>
                    <td>3</td>
                    <td><input input="qty"></input></td>
                </tr>
                       <% } %>
        </table>
        <input type="submit" value="Submit Restock">
        </form>
        <form action="indexReturn" method="POST">
        <input type="submit" value="Return to Menu">
        </form>
    </body>
</html>
