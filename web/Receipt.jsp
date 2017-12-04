<%-- 
    Document   : OrderConfirmation
    Created on : Nov 25, 2017, 1:15:35 AM
    Author     : Scott
--%>

<%-- <%@taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %> --%>
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.ManageInventory"%>
<%@page import = "InterfacePackages.transactionLog"%>
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
                Vector v = new Vector();
                    int size = (int)session.getAttribute("size");
                    
                    for(int i = 0; i < size;i++){
                        v.add(session.getAttribute("v"+i));
                    }

                    //ManageInventory manInv = new ManageInventory();
                    ManageInventory manInv = (ManageInventory)session.getAttribute("manInv");
                    Vector vecInv = new Vector();
                    vecInv = manInv.PullData();
                    
                    String money = (String)session.getAttribute("total");
                    pageContext.setAttribute("money", money);
                    
                    transactionLog tra = (transactionLog)session.getAttribute("tra");
                    
                    for(int i = 0; i < v.size();i++){
                        int T = Integer.parseInt((String)v.get(i));
                        Vector temp = new Vector();
                        temp = (Vector)vecInv.get(i);
                        if(T != 0){
                            int ID = (int)temp.get(1);
                            for(int j = 0;j < Integer.parseInt((String)v.get(i));j++)
                            {
                                tra.AddItem((String)temp.get(0), (int)temp.get(1), Integer.parseInt((String)v.get(i)), (int)temp.get(3));
                                manInv.DecQty(ID);
                            }
                        }
                    }
                    int sub = Integer.parseInt((String)session.getAttribute("subtot"));
                    int tax = Integer.parseInt((String)session.getAttribute("taxes"));
                    int tot = Integer.parseInt((String)session.getAttribute("total"));
                    pageContext.setAttribute("taxs", tax);
                    pageContext.setAttribute("subt", sub);
                    pageContext.setAttribute("totalM", tot);
                    
        %>
                <tr><% %></tr>
                <tr>Subtotal: $ ${subt} </tr>
                <tr>     Tax: $ ${taxs} </tr>
                <tr>   Total: $ ${totalM} </tr>
                
        <form action="indexReturn" method="POST">
        <input type="submit" value="Return to Menu">
        </form>
                       
    </body>
</html>
