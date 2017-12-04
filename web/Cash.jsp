<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title>Customer Interface</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <%--retrieve total variable--%>
        <table border ="0">
            <tr>Cash Payment System</tr>
            <tr>
                <%
                    String money = (String)session.getAttribute("total");
                    pageContext.setAttribute("money", money);
                %>
                <td>Payment Approved, Please take receipt! <br> Your change has been donated to the Wounded Warrior Project!</td>
                <td>${money}</td>
            </tr>
        </table>
            <td><form action="indexReturn" method="POST">
            <input type="submit" value="Start new order">
        </form></td>
    </body>
</html>
