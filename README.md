# Blackjack-game
A web application blackjack game made using C++ and hosted in browser via web assembly and JavaScript. With backend and cloud based database hosted in supabase.

[Play the game now](https://adallan.github.io/Blackjack-game/)

Please see: [game_logic.cpp](https://github.com/adallan/Blackjack-game/blob/main/game_logic_text_based.cpp) for the C++ text based-game code!
See [here](https://github.com/adallan/Blackjack-game/blob/main/game_logic_bindings.cpp) for the C++ Web Assembly bindings for JavaScript to use to run the game in a browser.

## Development Process
- Base Game Logic: Written in Vscode using C++.
- WebAssembly Intergration: Code is refactored and compiled with WebAssembly to create bindings.
- Comilation: Transformed bindings into a .js module and .wasm fiels using Enscripten.
- UI Development: HTML and JavaScript UI with WebAssembly module intergration and further game asset functions.
- Styling: Game assets, UI styled and scaled for all OS environments using CSS.
- Landing Page: Created to serve as a central hub for page navigation and user authentication.
- Cloud backend and Database:
  - Supabase hosted Postgres SQL database.
  - Supabase edge functions used to hsot backend Javascript.
  - Database stores users, stats and leaderboards.
  - Edge Functions handel authentication, leaderboard updating, backend functions and fetch calls from frontend.

## Full Stack Layer Overview
### Layer 1 - Presentation Layer
- User Interface in HTML/CSS/JavaScript hosted on github pages.

### Layer 2 - Client Communication Layer
- Browser networking via JavaScript using fetch to make rest API calls to Supabase Edge Functions.

### Layer 3 - Application Layer
- Backend API logic hosted on Supabase for serverless achitecture with auto-scaling.
- Authenticates users, logins, updates database.
  
### Layer 4 - Business Logic Layer
- Game rules and game logic, determining busts, wins and losses.
- Frontend JavaScript and C++ WebAssembly and backend Supabase Edge Functions to maintain consistency.

### Layer 5 - Data Layer
- Supabase Cloud-based Postgres database, stores users, their stats and the leaderboard data.

### Layer 6 - Infrastructure Layer
- Cloud-hosted servless Supabase and Github pages for frontend.

## Example of end to end flow
-> Player Clicks "Stand".
-> Frontend JavaScript calculates the result.
-> fetch("/edge-functions/game-save").
-> Backend validates.
-> Postgres updates the user stats.
-> Leaderbaord is refreshed.
-> Frontend fetches new leaderboard.

## Testing Process
- Base gameplay loop and logic testing and debugged in VsCode terminal in C++.
- HTML and JavaScript tested in browser via a Node live server.
- Landing page and game testing hosted in github pages for mobile and desktop debug.
- Database schema and funcationality testing in Postgres.
- Live game testing to troubleshot user profiles and leaderboards using node.js and a dockerize local postgres database.
- Edge functions and backend API tested with local node live-server with Supabase backend before frontend web mirgation.

## Next Steps and future updates
- Enhance user login system using OAuth support and JWT token managment.
- Possible kerbernetes implementation.
- Rebuild and refactor into React for framework relaibility and consistency.

Thanks for reading!
