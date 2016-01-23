#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "../../sh2/libft/includes/libft.h"
int
       main (int nb_args, char * args [])
       {
            struct stat    sts;

            if (nb_args != 2) {
                 fprintf (stderr, "syntaxe : %s <fichier>\n", args [0]);
                 exit (1);
            }

            if ( stat (args [1], & sts) != 0) {
                if (sts.st_mode % 10 == 0)
					printf("%s\n", "error : access");
                 exit (1);
            }
			char *lol;
			unsigned short poney;
			poney = (unsigned short)100777;
			lol = ft_itoa((int)sts.st_mode);          
            ft_putstr_fd(lol, 0);
           printf("%d\n", sts.st_dev);
           if (sts.st_mode == poney)
          	 	printf("%s\n", "lol");
            fprintf (stdout,
                 "Périphérique : %d\n",
                 sts . st_dev);
            fprintf (stdout,
                 "Noeud : %llu\n",
                 sts.st_ino);
            fprintf (stdout,
                 "Protection : %o\n",
                 sts . st_mode);
            fprintf (stdout,
                 "nb liens matériels: %d\n",
                 sts . st_nlink);
            fprintf (stdout,
                 "ID propriétaire : %d\n",
                 sts . st_uid);
            fprintf (stdout,
                 "ID groupe: %d\n",
                 sts . st_gid);
            fprintf (stdout,
                 "Taille : %lld octets\n",
                 sts . st_size);
            fprintf (stdout,
                 "Taille de bloc : %d\n",
                sts . st_blksize);
            fprintf (stdout,
                 "Nombre de blocs : %lld\n",
                 sts . st_blocks);
       }