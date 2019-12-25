// import 'bulma/css/bulma.css'




const url = "http://127.0.0.1:2222/"

// fetch(url)
//     .then(data=> {return data.json()})
//     .then(res=>{
//         createPopover("this", res.title);
//     })
//     .catch(error=>console.log(error))

document.body.style.overflowX ='hidden';
document.head.title = 'DataSloth - Train it! Build it! Launch it!'
document.body.style.fontFamily = '"Poppins", sans-serif'

const slothBg = '#777777'
const slothGreen = '#1c4545';
const slothBlue = '#8cffff';

const hero = document.createElement('section');
hero.className = 'hero is-primary';

const heroBody = document.createElement('div');
heroBody.className = 'hero-body';

const container = document.createElement('container');


const title = document.createElement('h1');
title.id = 'title';
title.className = "title";
title.textContent = 'test';

document.body.appendChild(hero);
hero.appendChild(heroBody);
heroBody.appendChild(container);
container.appendChild(title);

