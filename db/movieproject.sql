CREATE TABLE `유저` (
    `userid` varchar(20) NOT NULL,
    `pw` varchar(20) NOT NULL,
    `이름` varchar(20) NOT NULL,
    `생년월일` DATE NOT NULL,
    `전화번호` varchar(20) NOT NULL,
    `주소` TEXT NULL,
    `마케팅수신동의` ENUM('Y', 'N') NULL
);

CREATE TABLE `영화` (
    `movieid` varchar(20) NOT NULL,
    `영화명` varchar(20) NOT NULL,
    `영화장르` VARCHAR(20) NOT NULL,
    `평점` float(2,2) ,
    `줄거리` TEXT ,
    `포스터` text ,
    `주요인물` text
);
    
CREATE TABLE `마음함` (
`userid` varchar(20) NOT NULL,
 `movieid` varchar(20) NOT NULL

);

CREATE TABLE `게시판글` (
    `postid` varchar(20) NOT NULL,
    `userid` varchar(20) NOT NULL,
    `글내용` text,
    `글사진` BLOB,
    `글익명여부` ENUM('N', 'Y')
);

CREATE TABLE `게시판댓글` (
    `userid` varchar(20) NOT NULL,
    `postid` varchar(20) NOT NULL,
    `commentid` varchar(20) NOT NULL,
    `댓글` text,
    `댓글사진` BLOB,
    `댓글익명여부` ENUM('N', 'Y')
);

CREATE TABLE `결제` (
    `userid` varchar(20) NOT NULL,
    `movieid` varchar(20) NOT NULL,
    `링크` TEXT 
);



/*/ 여기서 부터는 PK 제약 추가 했음다 /*/
ALTER TABLE `유저` ADD CONSTRAINT `PK_유저_userid` primary KEY(`userid`) ;
ALTER TABLE `영화` ADD CONSTRAINT `PK_영화_movieid` primary KEY(`movieid`) ;
ALTER TABLE `게시판글` ADD CONSTRAINT `PK_게시판글_userid_postid` primary KEY(`postid`,`userid`) ;
ALTER TABLE `게시판댓글` ADD CONSTRAINT `PK_게시판댓글_userid_postid_commentid` primary key (`postid`, `userid`,`commentid`);
ALTER TABLE `마음함` ADD CONSTRAINT `PK_결제_userid_movieid` primary KEY(`userid`,`movieid`) ;
ALTER TABLE `결제` ADD CONSTRAINT `PK_결제_userid_movieid` primary KEY(`userid`,`movieid`) ;

/*/여기서부턴 FK 제약 추가 했음다 /*/
ALTER TABLE `마음함` ADD CONSTRAINT `FK_마음함_userid` FOREIGN KEY (`userid`) REFERENCES `유저` (`userid`);
ALTER TABLE `마음함` ADD CONSTRAINT `FK_마음함_movieid` FOREIGN KEY (`movieid`) REFERENCES `영화` (`movieid`);
ALTER TABLE `결제` ADD CONSTRAINT `FK_결제_userid` FOREIGN KEY (`userid`) REFERENCES `유저` (`userid`);
ALTER TABLE `결제` ADD CONSTRAINT `FK_결제_movieid` FOREIGN KEY (`movieid`) REFERENCES `영화` (`movieid`);
ALTER TABLE `게시판글` ADD CONSTRAINT `FK_게시판글_userid` FOREIGN KEY (`userid`) REFERENCES `유저` (`userid`);
ALTER TABLE `게시판댓글` ADD CONSTRAINT `FK_게시판댓글_userid` FOREIGN KEY (`userid`) REFERENCES `유저` (`userid`);
ALTER TABLE `게시판댓글` ADD CONSTRAINT `FK_게시판댓글_postid` FOREIGN KEY (`postid`) REFERENCES `게시판글` (`postid`);

SHOW CREATE TABLE `유저`;


/*/ id들은 a123128이렇게 들어갈거라 생각해서 int말고 varchar(20)으로 잡았습니당 /*/
/*/ 링크 나 포스터 이런건 링크로 타질거 같아서 text로 잡았습니다 /*/ 
/*/ 특이사항시 톡 주삼요 ^-^/*/