let overrideActive = false;
let confirmActive = false;
function mapRange(value, inMin, inMax, outMin, outMax) {
    return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}
const overrideButton = document.getElementById('Override');
const confirmButton = document.getElementById('confirm');
const statusText = document.getElementById('status');
const slider1value = document.getElementById('slider1Value');
const eng1per = document.getElementById('eng1per');
const slider2value = document.getElementById('slider2Value');
const eng2per = document.getElementById('eng2per');
const slider3value = document.getElementById('slider3Value');
const PWM1Value = document.getElementById('channel1');
const slider4value = document.getElementById('slider4Value');
const PWM2Value = document.getElementById('channel2');

slider1value.addEventListener('input', () => {
    eng1per.textContent = `Engine 1 Throttle: ${slider1value.value}%`;
});

slider2value.addEventListener('input', () => {
    eng2per.textContent = `Engine 2 Throttle: ${slider2value.value}%`;
});

slider3value.addEventListener('input', () => {
    PWM1Value.textContent = `Channel 1: ${slider3value.value}ms`;
});

slider4value.addEventListener('input', () => {
    PWM2Value.textContent = `Channel 2: ${slider4value.value}ms `;
});

overrideButton.addEventListener('click', () => {
    overrideActive = !overrideActive;
    if (overrideActive) {
    overrideButton.style.backgroundColor = 'green';
    confirmButton.style.backgroundColor = 'orange';
    }
    else {
        overrideButton.style.backgroundColor = 'red';
        confirmButton.style.backgroundColor = 'red';
        statusText.textContent = 'Controls Override: Inactive';
        statusText.style.backgroundColor = 'red';
    }
});

confirmButton.addEventListener('click', () => {
    confirmActive = !confirmActive;
    if (confirmActive && overrideActive) {
        confirmButton.style.backgroundColor = 'green';
        statusText.textContent = 'Controls Override: Active';
        statusText.style.backgroundColor = 'green';
    } else if (overrideActive) {
        confirmButton.style.backgroundColor = 'orange';
        statusText.textContent = 'Controls Override: Inactive';
        statusText.style.backgroundColor = 'red';
    }
    else {
        confirmButton.style.backgroundColor = 'red';
        statusText.textContent = 'Controls Override: Inactive';
        statusText.style.backgroundColor = 'red';
    }

});