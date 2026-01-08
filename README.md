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
- Database construction and schema.
- Backend API in Node to bridge between the game and database.

## Full Stack Layer Overview
### Layer 1 - Presentation Layer
- User Interface in HTML/CSS/JavaScript hosted on github pages.

### Layer 2 - Client Communication Layer
- Browser networking via JavaScript using fetch to make rest API calls.

### Layer 3 - Application Layer
- Backend API logic in Node.js hosted on Render.
- Authenticates users, logins, updates database.
  
### Layer 4 - Business Logic Layer
- Game rules and game logic, lives in both frontend and backend determining busts, wins and losses.

### Layer 5 - Data Layer
- Dockerized Postgres database, stores users, their stats and the leaderboard data.

### Layer 6 - Infrastructure Layer
- Docker and Hosting on Render and Github pages.

## Example of end to end flow
-> Player Clicks "Stand".
-> Frontend JavaScript calculates the result.
-> fetch("/save-progress").
-> Backend validates.
-> Postgres updates the user stats.
-> Leaderbaord is refreshed.
-> Frontend fetches new leaderboard.

## Testing Process
- Base gameplay loop and logic testing and debugged in VsCode terminal in C++.
- HTML and JavaScript tested in browser via a Node live server.
- Landing page and game testing hosted in github pages for mobile and desktop debug.
- Database schema and funcationality testing in Postgres.
- Live game testing to troubleshot user profiles and leaderboards.

## Next Steps and future updates
- Creation of user logins.
- Creation of highscore leaderboards.
- Docker pipeline.
- Possible kerbernetes implementation.

Thanks for reading!
