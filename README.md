# Blackjack-game
A blackjack game made using C++ and hosted in browser via web assembly and JavaScript.

Please see: [game_logic.cpp](https://github.com/adallan/Blackjack-game/blob/main/game_logic.cpp) for the C++ text based-game code!
See [here](https://github.com/adallan/Blackjack-game/blob/main/game_logic_bindings.cpp) for the C++ Web Assembly bindings for JavaScript to use to run the game in a browser.

## Development Process
- Base game logic codes in Visual Studio Code in C++.
- Code is refactored to be usable by Web Assembly, bindings created for classes and functions.
- Code is transformed into a .js and .wasm files to be used by JavaScript by Emscripten terminal functions.
- HTML UI and Javascript programmed utilzing the Module created by Web Assembly.
- Game assets added into UI design.
- CSS implemented for UI design and styling.
- Development of game's landing page.

## Testing Process
- Base gameplay loop and logic testing and debugged in VsCode terminal in C++.
- HTML and JavaScript tested in browser via a Node live server.
- NEXT testing: Landing page and game testing hosted in github pages.

Thanks for reading!
