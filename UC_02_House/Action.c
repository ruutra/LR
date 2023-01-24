Action()
{	
	web_url("um.mos.ru", 
		"URL=https://um.mos.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		LAST);


	web_url("houses", 
		"URL=https://um.mos.ru/houses", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://um.mos.ru/", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		LAST);


	web_url("houses_2", 
		"URL=https://um.mos.ru/houses", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://um.mos.ru/", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);


	web_url("houses_3", 
		"URL=https://um.mos.ru/api/v1/houses?page=1&filter[media]=audioFile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://um.mos.ru/houses?filters=audioFile", 
		"Snapshot=t103.inf", 
		"Mode=HTML", 
		LAST);


	web_url("houses_4", 
		"URL=https://um.mos.ru/houses?filters=audioFile", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t107.inf", 
		"Mode=HTML", 
		LAST);

	web_url("cerkov-voskreseniya-na-uspenskom-vrazhke0", 
		"URL=https://um.mos.ru/houses/cerkov-voskreseniya-na-uspenskom-vrazhke0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t130.inf", 
		"Mode=HTML", 
		EXTRARES,  
		"Url=../uploads/house/audio_files/4089/ru/163c66ad44d830.mp3", ENDITEM, 
		LAST);

	return 0;
}