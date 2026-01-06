# Blackjack-game
A blackjack game made using C++ and hosted in browser via web assembly and JavaScript.

[Play the game now](https://adallan.github.io/Blackjack-game/)

Please see: [game_logic.cpp](https://github.com/adallan/Blackjack-game/blob/main/game_logic_text_based.cpp) for the C++ text based-game code!
See [here](https://github.com/adallan/Blackjack-game/blob/main/game_logic_bindings.cpp) for the C++ Web Assembly bindings for JavaScript to use to run the game in a browser.

## Development Process
- Base game logic codes in Visual Studio Code in C++.
- Code is refactored to be usable by Web Assembly, bindings created for classes and functions.
- Code is transformed into a .js and .wasm files to be used by JavaScript by Emscripten terminal functions.
- HTML UI and Javascript programmed utilzing the Module created by Web Assembly.
- Game assets added into UI design.
- CSS implemented for UI design and styling.
- Development of game's landing page.
- Data flow and architecture.
- Database construction and schema

## Arcitecture overview
UI in Html/Css/JavaScript <-----> Backend C++ gane logic and Node.js
Backend C++ <------> Database in Postgres

- UI handles game visuals, interactions and betting.
- Backend handels game logic and in the future registration, save/load and leaderboards.
- Database will store users,game states and leaderboard information.

## Testing Process
- Base gameplay loop and logic testing and debugged in VsCode terminal in C++.
- HTML and JavaScript tested in browser via a Node live server.
- Landing page and game testing hosted in github pages for mobile and desktop debug.
- Database schema and funcationality testing in Postgres.
- Live game testing to troubleshot user profiles and leaderboards.

## Next Steps and future updates
- Creation of user logins.
- Creation of highscore leaderboards.
- Implementation and creation of a database to host user data and score datas.
- Docker pipeline.
- Possible kerbernetes implementation.

Thanks for reading!
