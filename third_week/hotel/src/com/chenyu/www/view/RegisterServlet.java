package com.chenyu.www.view;


import com.chenyu.www.dao.impl.UserDao;
import com.chenyu.www.dao.impl.UserDaoImpl;
import com.chenyu.www.service.UserService;
import com.chenyu.www.util.AppMD5Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

//注册界面的Servlet
public class RegisterServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //获取前端传来的信息
        String userAccount =request.getParameter("user_account");
        String userPassword =request.getParameter("user_password");
        String userName =request.getParameter("user_name");
        String userPhone =request.getParameter("user_phone");
        String userIdNumber=request.getParameter("user_idNumber");

        UserService u=new UserService();
        //将信息传入Service处理
        u.Register(userName,userPassword,userPhone,userAccount,userIdNumber,request,response);



    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
