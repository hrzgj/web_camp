<%--
  Created by IntelliJ IDEA.
  User: 86323
  Date: 2019/4/7
  Time: 20:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>修改用户信息成功</title>
</head>
<body>
<center>修改成功，稍后进入主界面</center>
<%
    response.setHeader("refresh","3;url=/hotel_war_exploded/Main.jsp");
%>
</body>
</html>
