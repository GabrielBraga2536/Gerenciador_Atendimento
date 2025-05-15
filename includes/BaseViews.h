#ifndef BASE_VIEWS_H
#define BASE_VIEWS_H

//* Declaração das funções padrões de exibição de menus e mensagens

/**
 * @brief Imprime no terminal a linha superior padrão de um menu.
 * @return 
 */
void MenuLinhaSuperior();

/**
 * @brief Imprime no terminal a linha inferior padrão de um menu.
 * @return 
 */
void MenuLinhaInferior();

/**
 * @brief Imprime no terminal a linha central padrão de um menu.
 * @param item - Texto a ser impresso na linha central.
 * @return 
 */
void MenuItem(char *item);

/**
 * @brief Imprime no terminal o título padrão de um menu.
 * @param titulo - Texto a ser impresso no título do menu.
 * @return 
 */
void MenuTitulo(char *titulo);

/**
 * @brief Imprime no terminal o título isolado padrão de um menu.
 * @param titulo - Texto a ser impresso no título do menu.
 * @return 
 */
void MenuTituloIsolado(char *titulo);

/**
 * @brief Imprime no terminal o título isolado padrão de um menu.
 * @return Retorna o número digitado pelo usuário referente a opção do menu.
 */
int MenuInputUsuario();

/**
 * @brief Imprime no terminal o menu de cadastro de pacientes.
 * @return 
 */
void ExibirMenuPrincipal();

#endif /* BaseViews_h */