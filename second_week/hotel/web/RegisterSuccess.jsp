<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/6
  Time: 22:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Insert title here</title>
</head>
<body>
<center>注册成功，稍后进入主界面</center>
<%
    response.setHeader("refresh","3;url=/hotel_war_exploded/Main.jsp");
%>

</body>
</html>
