/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:18:26 by vbleskin          #+#    #+#             */
/*   Updated: 2025/12/09 13:13:17 by vbleskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST(desc, format, ...) \
    do { \
        printf("\n%s\n", desc); \
        printf("   REAL: |"); \
        fflush(stdout); \
        int r1 = printf(format, ##__VA_ARGS__); \
        printf("| (ret: %d)\n", r1); \
        printf("   MINE: |"); \
        fflush(stdout); \
        int r2 = ft_printf(format, ##__VA_ARGS__); \
        printf("| (ret: %d)\n", r2); \
        if (r1 == r2) printf("   ✅ RET OK\n"); \
        else printf("   ❌ RET FAIL (Diff: %d)\n", r2 - r1); \
	} while (0)

int main(void)
{
		printf("==================================================\n");
		printf("           TESTS LIMITES & CAS LOUCHES            \n");
		printf("==================================================\n");

    // --- ENTIERS (d / i) ---
    TEST("1. Basique", "%d", 42);
    TEST("2. INT_MIN", "%d", INT_MIN);
    TEST("3. INT_MAX", "%d", INT_MAX);
    TEST("4. Zéro simple", "%d", 0);
    
    // Les cas Pièges de la Précision
    TEST("5. Precision .0 avec 0 (Doit rien afficher)", "%.0d", 0);
    TEST("6. Precision .0 avec nombre", "%.0d", 42);
    TEST("7. Precision et Largeur (Padding Espace)", "%5.3d", 1);
    TEST("8. Precision et Largeur (Padding Zero interdit)", "%05.3d", 1);
    
    // Les Signes
    TEST("9. Flag Plus positif", "%+d", 42);
    TEST("10. Flag Plus negatif", "%+d", -42);
    TEST("11. Flag Espace", "% d", 42);
    TEST("12. Flag Espace avec negatif", "% d", -42);
    TEST("13. Priorité Plus > Espace", "%+ d", 42);

    // --- NON SIGNÉS & HEXA (u / x / X) ---
    TEST("14. UINT MAX", "%u", UINT_MAX);
    TEST("15. Hexa Basique", "%x", 42);
    TEST("16. Hexa Hash (0x)", "%#x", 42);
    TEST("17. Hexa Hash avec 0 (Pas de 0x !)", "%#x", 0);
    TEST("18. Hexa Precision", "%.5x", 1);
    TEST("19. Hexa Hash + Zero + Largeur", "%#05x", 42);
    TEST("20. Hexa Hash + Moins + Largeur", "%-#5x", 42);

    // --- POINTEURS (p) ---
    int a = 42;
    void *ptr = &a;
    TEST("21. Pointeur valide", "%p", ptr);
    TEST("22. Pointeur NULL (Comportement (nil))", "%p", NULL);
    // Note: Sur p, les flags 0, +, espace sont indéfinis, on teste largeur/alignement
    TEST("23. Pointeur Largeur", "%20p", ptr);
    TEST("24. Pointeur Alignement Gauche", "%-20p", ptr);

    // --- STRINGS (s) ---
    TEST("25. String NULL (Crash test)", "%s", (char *)NULL);
    TEST("26. String Vide", "%s", "");
    TEST("27. Precision sur String", "%.3s", "Bonjour");
    TEST("28. Precision sur String NULL", "%.3s", (char *)NULL);
    TEST("29. Largeur + Precision", "%10.3s", "Bonjour");

    // --- CHARS (c) ---
    TEST("30. Char normal", "%c", 'A');
    TEST("31. Char Zero (Invisible mais ret=1)", "%c", 0);
    TEST("32. Char avec Largeur", "%5c", 'A');
    TEST("33. Char avec Largeur et 0", "%05c", 'A'); // Undefined mais souvent space ou 0

    // --- PERCENT (%) ---
    TEST("34. Percent", "%%");
    TEST("35. Percent aligné", "%-5%");
    TEST("36. Percent zero", "%05%");

    TEST("37. Mixte", "Num: %d, Str: %s, Hex: %#x", 42, "Test", 255);

    printf("\n==================================================\n");
    printf("                 FIN DES TESTS                    \n");
    printf("==================================================\n");

    return (0);
}

// int	main(void)
// {
// 	char	*str = "c -> %c\ns -> %s\np -> %p\nd -> %d\ni -> %i\nu -> %u\nx -> %x\nX -> %X\n% -> %%\n";
// 	char	*sent = "Python !!!";
// 	char	c = 'W';
// 	long	pt = -42;
// 	int		len;

//     len = ft_printf(NULL);
//     ft_printf("%d\n", len);
//     len = printf(NULL);
//     printf("%d\n", len);
// 	printf("-------- printf / ft_printf--------\n");
// 	len = printf(str, c, sent, pt, pt, pt, pt, pt, pt);
// 	printf("len --> %d\n\n", len);
// 	len = ft_printf(str, c, sent, pt, pt, pt, pt, pt, pt);
// 	ft_printf("len --> %d\n\n", len);
// 	printf("-------- printf / ft_printf (NULL) --------\n");
// 	len = printf(str, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
// 	printf("len --> %d\n\n", len);
// 	len = ft_printf(str, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
// 	ft_printf("len --> %d\n\n", len);
// 	printf("-------- printf / ft_printf (EMPTY) --------\n");
// 	len = printf(NULL);
// 	printf("len --> %d\n", len);
// 	len = ft_printf(NULL);
// 	ft_printf("len --> %d\n\n", len);
// 	ft_printf("------- mix test -------\n");
// 	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	printf("\n");
// 	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42,'C', "0", 0, 0 ,0 ,0, 42, 0);
// }