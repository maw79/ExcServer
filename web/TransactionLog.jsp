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
        <div>Please confirm your order below.</div>
        
        <%
                class order{
                public int order[];
                public int size=5;
                }
                
                for(int ii=0; ii< 5; ii++)
                {%>
                <div><% %>Transaction 1</div>
                       <% } %>
        <form action="indexReturn" method="POST">
        <input type="submit" value="Log Out">
        </form>
    </body>
</html>
