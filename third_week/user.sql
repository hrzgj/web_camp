/*
SQLyog Ultimate v12.5.0 (64 bit)
MySQL - 5.7.25-log 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

create table `user` (
	`user_id` int (11),
	`user_name` varchar (96),
	`user_account` varchar (96),
	`user_phone` varchar (36),
	`user_identity` int (1),
	`user_password` varchar (96),
	`user_idnumber` varchar (96)
); 
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('2','HR','8632340092b','13509897398','0','e4dd9c8cd0b86ec67b1c520b45e1acdd','445102199912041936');
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('3','HRE','863234009E','13509897398','0','f2d136ea22a5b6e0ed0120a03ab795c2','445102199912041936');
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('4','hr','863234009w','13509897398','0','9cbf8a4dcb8e30682b927f352d6559a0','445102199912041936');
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('5','hr','863234009c','13509897398','0','9cbf8a4dcb8e30682b927f352d6559a0','445102199912041936');
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('6','sdw','863234009a','13509897398','1','9cbf8a4dcb8e30682b927f352d6559a0','445102199912041936');
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('7','huange7','a123456','13413779543','0','60bcb86064911b27d385dbb29a5cc0d3','445102199912041936');
insert into `user` (`user_id`, `user_name`, `user_account`, `user_phone`, `user_identity`, `user_password`, `user_idnumber`) values('8','huange','863234009b','13509897398','0','7374ce58be384f97fb15117dd99fba3c','445102199912041936');
