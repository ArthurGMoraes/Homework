var url = document.URL; // Get current url
var url_array = url.split('=') // Split the string into an array with / as separator
var id = url_array[url_array.length-1];  // Get the last part of the array (-1)
console.log(id)

console.log ('Começou')

        fetch ('https://fakestoreapi.com/products')
           .then(res => res.json ())
           .then(data => {
                console.log ('Imprimindo produtos')
                let str = ''
                for (let i = 0; i < 1; i++) {
                    let produtos = data[id-1]
                    str += `<div class="container">
                    <div class="image">
                        <img src="${produtos.image}" id="imgdetalhes">
                    </div>
                    <div class="text" id="rounded-div">
                        <h5>${produtos.title}</h2>
                        <p>${produtos.description}</p>
                        <p>R$${produtos.price}</p>
                    </div>`

                        

                }
                document.getElementById('tela').innerHTML = str
           })
           
        console.log ('Terminou')

        


        