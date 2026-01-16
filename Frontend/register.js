const form= document.getElementById("sign_up_form");
const message= document.getElementById("message_text");

form.addEventListener('submit',async (e) => {
    e.preventDefault();

    const username = document.getElementById("username").value;
    const email = document.getElementById("email_text").value;
    const password = document.getElementById("password").value;

    try {
        const response = await fetch("https://uexoocaysoxxcplbcgly.supabase.co/functions/v1/register", {
            method: "POST",
            headers: { 
                "Content-Type": "application/json",
                "Authorization": "Bearer sb_publishable_fyQczZnLTyEE_fU2CMRjMw_wkrw19cU",
                "apikey": "sb_publishable_fyQczZnLTyEE_fU2CMRjMw_wkrw19cU"
            },
            body: JSON.stringify({username, email, password, name: "Functions"})
            });
            console.log("meow", username, email, password)
        const data = await response.json();

        if (response.ok){
            message.style.color ='gold';
            message.textContent ='Registration successful!';
        }
        else{
            message.style.color ='red';
            message.textContent= data.error || 'Registration failed';
        }}
    catch(err){
        message.style.color='red';
        message.textContent='Server Error: ' + err.message;
    }
});
function return_landing(){
    window.location.href = "./Blackjack_landing.html";
}
