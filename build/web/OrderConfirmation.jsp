<%-- 
    Document   : OrderConfirmation
    Created on : Nov 25, 2017, 1:15:35 AM
    Author     : Scott
--%>

<%-- <%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %> --%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.ManageInventory"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Order Confirmation</title>
    </head>
    <body>
        <div>Order Confirmation:</div>
        <tr>Please confirm your order below.</tr>
        
                <%
                    Vector vecInv = new Vector();
                    vecInv = (Vector)pageContext.findAttribute("v");
                    for(int ii=0; ii<vecInv.size(); ii++){
                        String names = "qty" + Integer.toString(ii);
                        Vector temp = new Vector();
                        temp = (Vector)vecInv.get(ii);
                        String name = (String)temp.get(0);
                        pageContext.setAttribute("name", name);
                        
                        int IDi = (int)temp.get(1);
                        String ID = Integer.toString(IDi);
                        pageContext.setAttribute("ID", ID);
                        
                        int stocki = (int)temp.get(2);
                        String stock = Integer.toString(stocki);
                        pageContext.setAttribute("stock", stock);
                        
                        int costi = (int)temp.get(3);
                        String cost = Integer.toString(costi);//do it
                        pageContext.setAttribute("cost", cost);
                        
                        int buyi = (int)temp.get(4);
                        String buy = Integer.toString(buyi);
                        pageContext.setAttribute("buy", buy);
                %>
                <tr>
                    <td>${ID}</td>
                    <td>${name}</td>
                    <td>${cost}</td>
                    <td>${stock}</td>
                    <td>${qty}</td>
                </tr>
                <tr>
                       <% } %>
                <tr>Subtotal: !!! </tr>
                <tr>     Tax: !!! </tr>
                <tr>   Total: !!! </tr>
                
        <table>
            <tr>
                <td><form action="PayCash" method="POST">
            <input type="submit" value="Pay By Cash">
        </form></td>
                <td><form action="PayCard" method="POST">
            <input type="submit" value="Pay By Card">
        </form></td>
                <td><form action="indexReturn" method="POST">
            <input type="submit" value="Cancel Order">
        </form></td>
            </tr>
        </table>
                       
    </body>
</html>
