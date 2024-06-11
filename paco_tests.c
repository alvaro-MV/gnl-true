  fd = open("files/empty", O_RDWR);
        TEST(/* 1 */ gnl(1000,  NULL);
                 /* 2 */ gnl(-1,  NULL); close(fd);
                 /* 3 */ gnl(fd,  NULL);)

        title("files/empty: ")
        fd = open("files/empty", O_RDWR);
        TEST(/* 1 */ gnl(fd, NULL);
                 /* 2 */ gnl(fd, NULL);) close(fd);

        title("files/nl: ")
        fd = open("files/nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "\n");
                 /* 2 */ gnl(fd, NULL);) close(fd);

        title("files/41_no_nl: ")
        fd = open("files/41_no_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "01234567890123456789012345678901234567890");
                 /* 2 */ gnl(fd, NULL);) close(fd);

        title("files/41_with_nl: ")
        fd = open("files/41_with_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "0123456789012345678901234567890123456789\n");
                 /* 2 */ gnl(fd, "0");
                 /* 3 */ gnl(fd, NULL);) close(fd);

        title("files/42_no_nl: ")
        fd = open("files/42_no_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "012345678901234567890123456789012345678901");
                /* 2 */ gnl(fd, NULL);) close(fd);

        title("files/42_with_nl: ")
        fd = open("files/42_with_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "01234567890123456789012345678901234567890\n");
        if (BUFFER_SIZE == 42) {
                 /* 2 */ char c = 0; read(fd, &c, 1); check(c == '1'); ++iTest;
             /* 3 */ gnl(fd, NULL);}
        else {
                 /* 2 */ gnl(fd, "1");
                 /* 3 */ gnl(fd, NULL);})
        iTest = 1; close(fd);

        title("files/43_no_nl: ")
        fd = open("files/43_no_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "0123456789012345678901234567890123456789012");
                /* 2 */ gnl(fd, NULL);) close(fd);

        title("files/43_with_nl: ")
        fd = open("files/43_with_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "012345678901234567890123456789012345678901\n");
                 /* 2 */ gnl(fd, "2");
                 /* 3 */ gnl(fd, NULL);) close(fd);

        title("files/multiple_nlx5: ")
        fd = open("files/multiple_nlx5", O_RDWR);
        TEST(/* 1 */ gnl(fd, "\n");
                 /* 2 */ gnl(fd, "\n");
                 /* 3 */ gnl(fd, "\n");
                 /* 4 */ gnl(fd, "\n");
                 /* 5 */ gnl(fd, "\n");
                 /* 6 */ gnl(fd, NULL);) close(fd);

        title("files/multiple_line_no_nl: ")
        fd = open("files/multiple_line_no_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "01234567890123456789012345678901234567890\n");
                 /* 2 */ gnl(fd, "987654321098765432109876543210987654321098\n");
                 /* 3 */ gnl(fd, "0123456789012345678901234567890123456789012\n");
                 /* 4 */ gnl(fd, "987654321098765432109876543210987654321098\n");
                 /* 5 */ gnl(fd, "01234567890123456789012345678901234567890");
                 /* 6 */ gnl(fd, NULL);) close(fd);

        title("files/multiple_line_with_nl: ")
        fd = open("files/multiple_line_with_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "9876543210987654321098765432109876543210\n");
                 /* 2 */ gnl(fd, "01234567890123456789012345678901234567890\n");
                 /* 3 */ gnl(fd, "987654321098765432109876543210987654321098\n");
                 /* 4 */ gnl(fd, "01234567890123456789012345678901234567890\n");
                 /* 5 */ gnl(fd, "9876543210987654321098765432109876543210\n");
                 /* 6 */ gnl(fd, NULL);) close(fd);

        title("files/alternate_line_nl_no_nl: ")
        fd = open("files/alternate_line_nl_no_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "98765432109876543210987654321098765432109\n");
                 /* 2 */ gnl(fd, "\n");
                 /* 3 */ gnl(fd, "012345678901234567890123456789012345678901\n");
                 /* 4 */ gnl(fd, "\n");
                 /* 5 */ gnl(fd, "9876543210987654321098765432109876543210987\n");
                 /* 6 */ gnl(fd, "\n");
                 /* 7 */ gnl(fd, "012345678901234567890123456789012345678901\n");
                 /* 8 */ gnl(fd, "\n");
                 /* 9 */ gnl(fd, "98765432109876543210987654321098765432109");
                 /* 10 */ gnl(fd, NULL);) close(fd);

        title("files/alternate_line_nl_with_nl: ")
        fd = open("files/alternate_line_nl_with_nl", O_RDWR);
        TEST(/* 1 */ gnl(fd, "01234567890123456789012345678901234567890\n");
                 /* 2 */ gnl(fd, "\n");
                 /* 3 */ gnl(fd, "987654321098765432109876543210987654321090\n");
                 /* 4 */ gnl(fd, "\n");
                 /* 5 */ gnl(fd, "0123456789012345678901234567890123456789012\n");
                 /* 6 */ gnl(fd, "\n");
                 /* 7 */ gnl(fd, "987654321098765432109876543210987654321090\n");
                 /* 8 */ gnl(fd, "\n");
                 /* 9 */ gnl(fd, "01234567890123456789012345678901234567890\n");
                 /* 10 */ gnl(fd, NULL);) close(fd);

        title("files/big_line_no_nl: ")
