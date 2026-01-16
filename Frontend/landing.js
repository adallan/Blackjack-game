function game_page(){
    window.location.href = "./blackjack.html";
}
function register_page(){
    window.location.href = "./blackjack-register.html";
}
function leaderboard_page(){
    window.location.href = "./blackjack_leaderboard.html";
}
function login_show(){
    document.getElementById("login_form").style.display = "flex";
}

const login_form = document.getElementById("login_form");
const login_msg = document.getElementById("login_msg");

login_form.addEventListener("submit", async (e) => {
    e.preventDefault();

    const username = document.getElementById("login_username").value;
    const password = document.getElementById("login_password").value;

    try {
        const res = await fetch("https://uexoocaysoxxcplbcgly.supabase.co/functions/v1/login",{
            method: "POST",
            headers: { 
                "Content-Type": "application/json",
                "Authorization": "Bearer sb_publishable_fyQczZnLTyEE_fU2CMRjMw_wkrw19cU",
                "apikey": "sb_publishable_fyQczZnLTyEE_fU2CMRjMw_wkrw19cU"
            },
            body: JSON.stringify({ username, password, name: 'Functions'})
        });

        const data = await res.json();
        
        if (!res.ok){
            login_msg.style.color = "red";
            login_msg.textContent = data.error;
            return;
        }
        
        //Save user locally
        localStorage.setItem("user_id", data.user_id);
        localStorage.setItem("username", username);

        login_msg.style.color = "gold";
        login_msg.textContent = "Successfully logged in as: " + username;

        setTimeout(() => {
            game_page();
        }, 2000);
    }
    catch (err) {
        console.log(err)
    login_msg.style.color = "red";
    login_msg.textContent = "Server error";
  }
});