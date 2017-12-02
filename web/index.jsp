<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.ManageInventory"%>
<html>
    <head>
        <title>Customer Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <div>Welcome to the Interactive Purchase Order System!</div>
        <div>Please proceed with your purchase below.</div>
        <form action="CustOrder" method="POST">
            <table border ="1">
                <tr>
                    <td>Item No</td>
                    <td>Item Name</td>
                    <td>Cost</td>
                    <td>In Stock</td>
                    <td>Qty</td>
                </tr>
                <%
                    ManageInventory manInv = new ManageInventory();
                    Vector vecInv = new Vector();
                    vecInv = manInv.PullData();

                    //merchandise.size()
                    for(int ii=0; ii<vecInv.size(); ii++){
                        String names = "qty" + Integer.toString(ii);
                        Vector temp = new Vector();
                        temp = (Vector)vecInv.get(ii);
                        String name = (String)temp.get(0);
                        pageContext.setAttribute("name", name);
                        
                        int IDi = (int)temp.get(1);
                        String ID = Integer.toString(IDi);
                        pageContext.setAttribute("ID", ID);
                        
                        int qtyi = (int)temp.get(2);
                        String qty = Integer.toString(qtyi);
                        pageContext.setAttribute("qty", qty);
                        
                        int costi = (int)temp.get(3);
                        String cost = Integer.toString(costi);
                        pageContext.setAttribute("cost", cost);%>
                    <tr>
                        <td>${ID}</td>
                        <td>${name}</td>
                        <td>${cost}</td>
                        <td>${qty}</td>
                        <td><input type="integer" name=names ></input></td>
                    </tr>
                           <% } %>
            </table>
            <input type="submit" value="Submit Order">
        </form>
        <form action="ManagerMenu" method="POST">
            <input type="submit" value="Manager Menu">
        </form>
        <form action="RestockerMenu" method="POST">
            <input type="submit" value="Restocker Menu">
        </form>
    </body>
</html>
