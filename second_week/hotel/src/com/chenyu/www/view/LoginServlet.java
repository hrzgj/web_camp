package com.chenyu.www.view;



import com.chenyu.www.service.UserService;
import com.chenyu.www.util.AppMD5Util;


import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;



public class LoginServlet extends javax.servlet.http.HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        String userAccount =request.getParameter("user_account");
        String userPassword =request.getParameter("user_password");
        userPassword= AppMD5Util.getMD5(userPassword);
        UserService s=new UserService();
        s.login(userAccount,userPassword,request,response);

    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response) {

    }
}
