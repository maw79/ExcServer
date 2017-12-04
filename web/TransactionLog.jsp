<%-- 
    Document   : OrderConfirmation
    Created on : Nov 25, 2017, 1:15:35 AM
    Author     : Scott
--%>

<%-- <%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %> --%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.transactionLog"%>
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
                Vector curLog = new Vector();
                transactionLog Tlog = (transactionLog)session.getAttribute("tra");
                curLog = Tlog.PullData();
                for(int i=0; i< curLog.size(); i++)
                {
                    Vector temp = new Vector();
                    temp = (Vector)curLog.get(i);
                    pageContext.setAttribute("Name",(String)temp.get(0));
                    pageContext.setAttribute("ID",temp.get(1));
                    pageContext.setAttribute("Stk",temp.get(2));
                    pageContext.setAttribute("Cost",temp.get(3));
        %>
                <div><% %>Item : ${Name} $ ${Cost}  #: ${ID}  QtySold: ${Stk}</div>
                       <% } %>
        <form action="indexReturn" method="POST">
        <input type="submit" value="Log Out">
        </form>
    </body>
</html>
