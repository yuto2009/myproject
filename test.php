<?php
try {
		$db = new PDO('mysql:dbname=sample;host=127.0.0.1;charset=utf8mb4', 'root', '');
		$db -> exec('insert into profile values(1, "自分の名前", 16, current_timestamp)');

		print '<h1>DB接続成功</h1>';

		$records = $db->query('select * from profile');
                       while($record = $records->fetch()) {
                                     print $record['id'] . '<br>';
                       }
	} catch(PDOException $e) {
		print 'DB接続エラー：' . $e->getMessage();
	}

?>
