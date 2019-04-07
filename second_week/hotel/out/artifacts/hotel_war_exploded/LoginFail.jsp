<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/6
  Time: 20:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Insert title here</title>
</head>
<body>
<center>账户密码错误。登录失败,稍后跳转登录页面......</center>
<%
    response.setHeader("refresh","3;url=/hotel_war_exploded/Login.jsp");
%>

</body>
</html>
