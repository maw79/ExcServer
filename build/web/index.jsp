<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<%@page import = "java.util.*"%>
<%@page import = "InterfacePackages.ManageInventory"%>
<%@page import = "InterfacePackages.transactionLog"%>
<html>
    <head>
        <title>Customer Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
    <center>
        <h1>Welcome to the Interactive Purchase Order System!</h1>
        </br>
        <div>Please Specify Quantity to Purchase</div>
        <form action="CustOrder" method="POST">
            <table border ="1">
                <tr>
                    <td>Product ID</td>
                    <td>Product Name</td>
                    <td>Cost</td>
                    <td>Inventory Stock</td>
                    <td>Quantity to Purchase</td>
                </tr>
                <%
                    ManageInventory manInv = new ManageInventory();
                    Vector vecInv = new Vector();
                    session.setAttribute("manInv",manInv);
                    vecInv = manInv.PullData();
                    
                    transactionLog tra = new transactionLog();
                    session.setAttribute("tra", tra);

                    //merchandise.size()
                    for(int ii=0; ii<vecInv.size(); ii++){
                        int size = vecInv.size();
                        session.setAttribute("size", size);
                        //session.setAttribute("vinv"+ii, vecInv.get(ii));
                        Vector t = new Vector();
                        t = (Vector)vecInv.get(ii);
                        
                        session.setAttribute("vinv-name-"+ii, t.get(0));
                        session.setAttribute("vinv-ID-"+ii, t.get(1));
                        session.setAttribute("vinv-inv-"+ii, t.get(2));
                        session.setAttribute("vinv-cost-"+ii, t.get(3));
                        
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
                        pageContext.setAttribute("cost", cost);%>
                    <tr>
                        <td>${ID}</td>
                        <td>${name}</td>
                        <td>${cost}</td>
                        <td>${stock}</td>
                        <%
                            String nme = "qty" + Integer.toString(ii);
                            pageContext.setAttribute("nme", nme);
                        %>
                        <td><input type="integer" name=${nme} value="0"></input></td>
                    </tr>
                           <% } %>
            </table>
            <input type="submit" value="Submit Order">
        </form>
        <form action="ManagerMenu" method="POST">
            <input type="submit" value="Manager Menu">
        </form>
        <form action="RestockerInt.jsp">
            <input type="submit" value="Restocker Menu">
        </form>
    </center>
    </body>
</html>
