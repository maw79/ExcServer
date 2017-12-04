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
        <title>Receipt</title>
    </head>
    <body>
        <div>Receipt:</div>
        <tr>Here is what you have bought with us today.</tr>
        
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
                    
                    for(int i = 0;i<size;i++){
                        pageContext.setAttribute("N",null);
                        pageContext.setAttribute("C",null);
                        pageContext.setAttribute("Num",null);
                        int T = Integer.parseInt((String)v.get(i));
                        if(T != 0){
                            Vector temp = new Vector();
                            temp = (Vector)vecInv.get(i);
                            pageContext.setAttribute("N",(String)temp.get(0));
                            pageContext.setAttribute("C",temp.get(3));
                            pageContext.setAttribute("Num",Integer.parseInt((String)v.get(i)));
                        
        %>
                <tr><br> Item : ${N} $ ${C}  #: ${Num} </tr>
<%                      }
                    } 
                %>
                <tr><br>Subtotal: $ ${subt} </tr>
                <tr><br>     Tax: $ ${taxs} </tr>
                <tr><br>   Total: $ ${totalM} </tr>
                
        <form action="indexReturn" method="POST">
        <input type="submit" value="Return to Menu">
        </form>
                       
    </body>
</html>
