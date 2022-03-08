CREATE TABLE User 
( 
    id INTEGER PRIMARY KEY AUTO_INCREMENT, 
    username VARCHAR(64) NOT NULL,
    password VARCHAR(256) NOT NULL
);


INSERT INTO User (username, password) VALUES ('homer', '2aaab795b3836904f82efc6ca2285d927aed75206214e1da383418eb90c9052f');
INSERT INTO User (username, password) VALUES ('bart', '9551dadbf76a27457946e70d1aebebe2132f8d3bce6378d216c11853524dd3a6');
INSERT INTO User (username, password) VALUES ('lisa', 'd84fe7e07bedb227cffff10009151d96fc944f6a1bd37cff60e8e4626a1eb1c3');


