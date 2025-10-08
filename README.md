# Jogo War em C

Uma implementação simplificada do jogo de tabuleiro War (Risk-like) em linguagem C. Usa conceitos avançados como structs, ponteiros, alocação dinâmica de memória (`malloc`/`free`), strings (`strcpy`/`strcmp`), loops e funções modulares.

## Funcionalidades
- **Cadastro de Territórios**: Atualize nome, cor (jogador), número de tropas e continente via ID.
- **Exibição de Territórios**: Lista todos os 10 territórios iniciais (Ásia, América do Sul, América do Norte e Europa).
- **Simulação de Ataques**: Ataque entre territórios com mecânica aleatória (baseada em `rand()`). Regras: Pelo menos 2 tropas no atacante; não ataca aliados. Vencedor conquista o território.
- **Verificação de Vitória**: Missão estratégica – conquiste todos os territórios da Ásia (4) **e** América do Sul (3) com a cor do jogador para vencer.

Territórios iniciais (todos "neutro"):
- Ásia: China (5 tropas), India (4), Japao (3), Coreia (2).
- América do Sul: Brasil (4), Argentina (3), Venezuela (2).
- Outros: EUA (6), Mexico (3), Russia (5).

## Como Compilar e Executar
1. Instale GCC (compilador C): No Linux/macOS: `sudo apt install gcc` ou `brew install gcc`. No Windows: MinGW ou Visual Studio Code com extensão C.
2. No terminal/prompt, navegue até a pasta do projeto: `cd caminho/para/projeto`.
3. Compile: `gcc war.c -o war` (Linux/macOS) ou `gcc war.c -o war.exe` (Windows).
4. Execute: `./war` (Linux/macOS) ou `war.exe` (Windows).
5. Use o menu interativo:
   - 1: Exibir territórios.
   - 2: Atualizar território (ex: ID 0 para China).
   - 3: Ataque (ex: ID 0 ataca ID 4).
   - 4: Verificar vitória (ex: cor "vermelho").
   - 5: Sair.

## Exemplo de Saída

### Exemplo de Execução Completa
Aqui vai um fluxo simulado de jogo (inputs em *itálico*):

Bem-vindo ao Jogo War em C!
Este programa implementa cadastro de territórios, ataques e missões estratégicas.

Menu:
1. Exibir territórios
2. Cadastrar/atualizar território (por ID)
3. Realizar ataque (digite IDs)
4. Verificar vitória para um jogador (digite cor)
5. Sair
Escolha: *1*  (Usuário escolhe exibir territórios)

=== Lista de Territórios ===
ID: 0 | Nome: China | Cor: neutro | Tropas: 5 | Continente: Asia
ID: 1 | Nome: India | Cor: neutro | Tropas: 4 | Continente: Asia
ID: 2 | Nome: Japao | Cor: neutro | Tropas: 3 | Continente: Asia
ID: 3 | Nome: Coreia | Cor: neutro | Tropas: 2 | Continente: Asia
ID: 4 | Nome: Brasil | Cor: neutro | Tropas: 4 | Continente: AmericaSul
ID: 5 | Nome: Argentina | Cor: neutro | Tropas: 3 | Continente: AmericaSul
ID: 6 | Nome: Venezuela | Cor: neutro | Tropas: 2 | Continente: AmericaSul
ID: 7 | Nome: EUA | Cor: neutro | Tropas: 6 | Continente: AmericaNorte
ID: 8 | Nome: Mexico | Cor: neutro | Tropas: 3 | Continente: AmericaNorte
ID: 9 | Nome: Russia | Cor: neutro | Tropas: 5 | Continente: Europa
============================

Menu:
1. Exibir territórios
2. Cadastrar/atualizar território (por ID)
3. Realizar ataque (digite IDs)
4. Verificar vitória para um jogador (digite cor)
5. Sair
Escolha: *2*  (Usuário escolhe cadastrar/atualizar)

Digite o ID do território (0-9): *0*  (Atualiza China)
Digite o nome do território: *ChinaVermelha*  (Opcional, mas pode mudar)
Digite a cor (jogador): *vermelho*
Digite o número de tropas: *10*
Digite o continente: *Asia*
Território atualizado!

Menu:
... (menu aparece de novo)
Escolha: *2*  (Repete para mais territórios da Ásia e Am. Sul)

[Repetindo para IDs 1,2,3 (Ásia) e 4,5,6 (Am. Sul): Cada um atualizado para cor "vermelho" com tropas variadas, ex: 8 para India, etc. Saída: "Território atualizado!" para cada.]

Menu:
... 
Escolha: *1*  (Exibe após atualizações – agora Ásia e Am. Sul são "vermelho")

=== Lista de Territórios ===
ID: 0 | Nome: ChinaVermelha | Cor: vermelho | Tropas: 10 | Continente: Asia
ID: 1 | Nome: India | Cor: vermelho | Tropas: 8 | Continente: Asia
ID: 2 | Nome: Japao | Cor: vermelho | Tropas: 7 | Continente: Asia
ID: 3 | Nome: Coreia | Cor: vermelho | Tropas: 6 | Continente: Asia
ID: 4 | Nome: Brasil | Cor: vermelho | Tropas: 9 | Continente: AmericaSul
ID: 5 | Nome: Argentina | Cor: vermelho | Tropas: 8 | Continente: AmericaSul
ID: 6 | Nome: Venezuela | Cor: vermelho | Tropas: 7 | Continente: AmericaSul
ID: 7 | Nome: EUA | Cor: neutro | Tropas: 6 | Continente: AmericaNorte
ID: 8 | Nome: Mexico | Cor: neutro | Tropas: 3 | Continente: AmericaNorte
ID: 9 | Nome: Russia | Cor: neutro | Tropas: 5 | Continente: Europa
============================

Menu:
...
Escolha: *3*  (Usuário escolhe atacar – exemplo: vermelho ataca neutro)

Digite ID do atacante: *0*  (ChinaVermelha, com 10 tropas)
Digite ID do defensor: *7*  (EUA, neutro com 6 tropas)

=== Simulando Ataque: ChinaVermelha (atacante) vs EUA (defensor) ===

Defensor perde 1 tropa. Tropas restantes: 5
Atacante perde 1 tropa. Tropas restantes: 9
Defensor perde 1 tropa. Tropas restantes: 4
Defensor perde 1 tropa. Tropas restantes: 3
Atacante perde 1 tropa. Tropas restantes: 8
Defensor perde 1 tropa. Tropas restantes: 2
Defensor perde 1 tropa. Tropas restantes: 1
Defensor perde 1 tropa. Tropas restantes: 0
Vitória! EUA conquistado por vermelho.
==============================

Menu:
...
Escolha: *4*  (Verifica vitória – mas ainda não, pois EUA não é missão)

Digite a cor do jogador: *vermelho*
Missão Ásia concluída para vermelho!
Missão América do Sul concluída para vermelho!
Vitória para vermelho! Jogo concluído.

Menu:
...
Escolha: *5*  (Sair)

=== Lista de Territórios ===
[Lista final, com EUA agora "vermelho" e 7 tropas (8-1), etc.]
============================
Memória liberada.
