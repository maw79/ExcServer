<%-- 
    Document   : OrderConfirmation
    Created on : Nov 25, 2017, 1:15:35 AM
    Author     : Scott
--%>

<%-- <%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %> --%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
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
                class order{
                public int order[];
                public int size=5;
                }
                
                for(int ii=0; ii< 5; ii++)
                {%>
                <tr><% %></tr>
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
