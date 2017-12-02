/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package InterfacePackages;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Scott
 */
@WebServlet(name = "CashPayment", urlPatterns = {"/CashPayment"})
public class CashPayment extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            float cash = request.getParameter("cash");
            float total = request.getParameter("total");
            
            if(cash<=0){
                RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/BSOD.jsp");
                RequetsDispatcherObj.forward(request, response);
            
            if(cash<total){
                total=total-cash;
                RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/Cash.jsp");
                RequetsDispatcherObj.forward(request, response);
            }else if(cash>total){
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                out.println("<head>");
                out.println("<title>Servlet CashPayment</title>");            
                out.println("</head>");
                out.println("<body>");
                out.println("<h1>Please Take Your Change!</h1>");
                out.println("<div>Your change is " + (cash-total) "</div>");
                out.println("</body>");
                out.println("</html>");
                
                ~stop code~
                ~thank you button to continue~
                
                RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/Receipt.jsp");
                RequetsDispatcherObj.forward(request, response);
            }else{
                RequestDispatcher RequetsDispatcherObj =request.getRequestDispatcher("/Receit.jsp");
                RequetsDispatcherObj.forward(request, response);
            }
            
            
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
